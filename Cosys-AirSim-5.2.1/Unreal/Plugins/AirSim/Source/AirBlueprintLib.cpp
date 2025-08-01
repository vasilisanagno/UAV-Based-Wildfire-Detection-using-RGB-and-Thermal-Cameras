// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "AirBlueprintLib.h"
#include "GameFramework/WorldSettings.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/SkinnedMeshComponent.h"
#include <CineCameraActor.h>
#include <CineCameraComponent.h>
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "UObject/UObjectIterator.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerStart.h"
#include "Misc/MessageDialog.h"
#include "Engine/LocalPlayer.h"
#include "Engine/SkeletalMesh.h"
#include "Slate/SceneViewport.h"
#include "IImageWrapper.h"
#include "Misc/ObjectThumbnail.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include <exception>
#include "common/common_utils/Utils.hpp"
#include "Modules/ModuleManager.h"
#include "AssetRegistry/ARFilter.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "DetectionComponent.h"
#include "Components/LineBatchComponent.h"
#include "CineCameraComponent.h"

/*
//TODO: change naming conventions to same as other files?
Naming conventions in this file:
Methods -> CamelCase
parameters -> camel_case
*/

bool UAirBlueprintLib::log_messages_hidden_ = false;
uint32_t UAirBlueprintLib::flush_on_draw_count_ = 0;
IImageWrapperModule* UAirBlueprintLib::image_wrapper_module_ = nullptr;

void UAirBlueprintLib::LogMessageString(const std::string& prefix, const std::string& suffix, LogDebugLevel level, float persist_sec)
{
    LogMessage(FString(prefix.c_str()), FString(suffix.c_str()), level, persist_sec);
}

EAppReturnType::Type UAirBlueprintLib::ShowMessage(EAppMsgType::Type message_type, const std::string& message, const std::string& title)
{
    FText title_text = FText::FromString(title.c_str());

    return FMessageDialog::Open(message_type,
                                FText::FromString(message.c_str()),
                                &title_text);
}

ULineBatchComponent* GetLineBatcher(const UWorld* InWorld, bool bPersistentLines, float LifeTime, bool bDepthIsForeground)
{
	return (InWorld ? (bDepthIsForeground ? InWorld->ForegroundLineBatcher : ((bPersistentLines || (LifeTime > 0.f)) ? InWorld->PersistentLineBatcher : InWorld->LineBatcher)) : NULL);
}

static float GetLineLifeTime(ULineBatchComponent* LineBatcher, float LifeTime, bool bPersistent)
{
	return bPersistent ? -1.0f : ((LifeTime > 0.f) ? LifeTime : LineBatcher->DefaultLifeTime);
}

void UAirBlueprintLib::DrawCoordinateSystem(const UWorld* InWorld, FVector const& AxisLoc, FRotator const& AxisRot, float Scale, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
    // no debug line drawing on dedicated server
    if (GEngine->GetNetMode(InWorld) != NM_DedicatedServer)
    {
        FRotationMatrix R(AxisRot);
        FVector const X = R.GetScaledAxis(EAxis::X);
        FVector const Y = R.GetScaledAxis(EAxis::Y);
        FVector const Z = R.GetScaledAxis(EAxis::Z);

        // this means foreground lines can't be persistent
        ULineBatchComponent* const LineBatcher = GetLineBatcher(InWorld, bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
        if (LineBatcher != NULL)
        {
            float const LineLifeTime = GetLineLifeTime(LineBatcher, LifeTime, bPersistentLines);
            LineBatcher->DrawLine(AxisLoc, AxisLoc + X * Scale, FColor::Red, DepthPriority, Thickness, LineLifeTime);
            LineBatcher->DrawLine(AxisLoc, AxisLoc + Y * Scale, FColor::Green, DepthPriority, Thickness, LineLifeTime);
            LineBatcher->DrawLine(AxisLoc, AxisLoc + Z * Scale, FColor::Blue, DepthPriority, Thickness, LineLifeTime);
        }
    }
}

void UAirBlueprintLib::DrawLine(const UWorld* InWorld, FVector const& LineStart, FVector const& LineEnd, FColor const& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
	// no debug line drawing on dedicated server
	if (GEngine->GetNetMode(InWorld) != NM_DedicatedServer)
	{
		// this means foreground lines can't be persistent
		ULineBatchComponent* const LineBatcher = GetLineBatcher(InWorld, bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
		if (LineBatcher != NULL)
		{
			float const LineLifeTime = GetLineLifeTime(LineBatcher, LifeTime, bPersistentLines);
			LineBatcher->DrawLine(LineStart, LineEnd, Color, DepthPriority, Thickness, LineLifeTime);
		}
	}
}

void UAirBlueprintLib::DrawPoint(const UWorld* InWorld, FVector const& Position, float Size, FColor const& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority)
{
	// no debug line drawing on dedicated server
	if (GEngine->GetNetMode(InWorld) != NM_DedicatedServer)
	{
		// this means foreground lines can't be persistent
		ULineBatchComponent* const LineBatcher = GetLineBatcher(InWorld, bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
		if (LineBatcher != NULL)
		{
			const float PointLifeTime = GetLineLifeTime(LineBatcher, LifeTime, bPersistentLines);
			LineBatcher->DrawPoint(Position, Color.ReinterpretAsLinear(), Size, DepthPriority, PointLifeTime);
		}
	}
}

static void InternalDrawCircle(const UWorld* InWorld, const FMatrix& TransformMatrix, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness = 0.f)
{
	// no debug line drawing on dedicated server
	if (GEngine->GetNetMode(InWorld) != NM_DedicatedServer)
	{
		ULineBatchComponent* const LineBatcher = GetLineBatcher(InWorld, bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
		if (LineBatcher != NULL)
		{
			const float LineLifeTime = GetLineLifeTime(LineBatcher, LifeTime, bPersistentLines);

			// Need at least 4 segments
			Segments = FMath::Max(Segments, 4);
			const float AngleStep = 2.f * PI / float(Segments);

			const FVector Center = TransformMatrix.GetOrigin();
			const FVector AxisY = TransformMatrix.GetScaledAxis(EAxis::Y);
			const FVector AxisZ = TransformMatrix.GetScaledAxis(EAxis::Z);

			TArray<FBatchedLine> Lines;
			Lines.Empty(Segments);

			float Angle = 0.f;
			while (Segments--)
			{
				const FVector Vertex1 = Center + Radius * (AxisY * FMath::Cos(Angle) + AxisZ * FMath::Sin(Angle));
				Angle += AngleStep;
				const FVector Vertex2 = Center + Radius * (AxisY * FMath::Cos(Angle) + AxisZ * FMath::Sin(Angle));
				Lines.Add(FBatchedLine(Vertex1, Vertex2, Color, LineLifeTime, Thickness, DepthPriority));
			}
			LineBatcher->DrawLines(Lines);
		}
	}
}

void UAirBlueprintLib::DrawCircle(const UWorld* InWorld, const FMatrix& TransformMatrix, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness, bool bDrawAxis)
{
	// no debug line drawing on dedicated server
	if (GEngine->GetNetMode(InWorld) != NM_DedicatedServer)
	{
		ULineBatchComponent* const LineBatcher = GetLineBatcher(InWorld, bPersistentLines, LifeTime, (DepthPriority == SDPG_Foreground));
		if (LineBatcher != NULL)
		{
			const float LineLifeTime = GetLineLifeTime(LineBatcher, LifeTime, bPersistentLines);

			// Need at least 4 segments
			Segments = FMath::Max((Segments - 2) / 2, 4);
			InternalDrawCircle(InWorld, TransformMatrix, Radius, Segments, Color, bPersistentLines, LifeTime, DepthPriority, Thickness);

			if (bDrawAxis)
			{
				const FVector Center = TransformMatrix.GetOrigin();
				const FVector AxisY = TransformMatrix.GetScaledAxis(EAxis::Y);
				const FVector AxisZ = TransformMatrix.GetScaledAxis(EAxis::Z);

				TArray<FBatchedLine> Lines;
				Lines.Empty(2);
				Lines.Add(FBatchedLine(Center - Radius * AxisY, Center + Radius * AxisY, Color, LineLifeTime, Thickness, DepthPriority));
				Lines.Add(FBatchedLine(Center - Radius * AxisZ, Center + Radius * AxisZ, Color, LineLifeTime, Thickness, DepthPriority));
				LineBatcher->DrawLines(Lines);
			}
		}
	}
}

void UAirBlueprintLib::DrawCircle(const UWorld* InWorld, FVector Center, float Radius, int32 Segments, const FColor& Color, bool PersistentLines, float LifeTime, uint8 DepthPriority, float Thickness, FVector YAxis, FVector ZAxis, bool bDrawAxis)
{
	FMatrix TM;
	TM.SetOrigin(Center);
	TM.SetAxis(0, FVector(1, 0, 0));
	TM.SetAxis(1, YAxis);
	TM.SetAxis(2, ZAxis);

	DrawCircle(
		InWorld,
		TM,
		Radius,
		Segments,
		Color,
		PersistentLines,
		LifeTime,
		DepthPriority,
		Thickness,
		bDrawAxis
	);
}


void UAirBlueprintLib::enableWorldRendering(AActor* context, bool enable)
{
    ULocalPlayer* player = context->GetWorld()->GetFirstLocalPlayerFromController();
    if (player) {
        UGameViewportClient* viewport_client = player->ViewportClient;
        if (viewport_client) {
            viewport_client->bDisableWorldRendering = enable;
        }
    }
}

void UAirBlueprintLib::setSimulatePhysics(AActor* actor, bool simulate_physics)
{
    TInlineComponentArray<UPrimitiveComponent*> components;
    actor->GetComponents(components);

    for (UPrimitiveComponent* component : components) {
        component->SetSimulatePhysics(simulate_physics);
    }
}

bool UAirBlueprintLib::loadLevel(UObject* context, const FString& level_name)
{

    bool success{ false };
    // Get name of current level
    auto currMap = context->GetWorld()->GetMapName();
    currMap.RemoveFromStart(context->GetWorld()->StreamingLevelsPrefix);
    // Only load new level if different from current level
    if (!currMap.Equals(level_name)) {
        FString LongPackageName;
        success = FPackageName::SearchForPackageOnDisk(level_name, &LongPackageName);
        if (success) {
            context->GetWorld()->SetNewWorldOrigin(FIntVector(0, 0, 0));
            UGameplayStatics::OpenLevel(context->GetWorld(), FName(*LongPackageName), true);
        }
    }
    return success;
}

bool UAirBlueprintLib::spawnPlayer(UWorld* context)
{

    bool success{ false };
    TArray<AActor*> player_start_actors;
    FindAllActor<APlayerStart>(context, player_start_actors);
    if (player_start_actors.Num() > 1) {
        for (auto player_start : player_start_actors) {
            if (player_start->GetName() != FString("SuperStart")) {
                //context->GetWorld()->SetNewWorldOrigin(FIntVector(0, 0, 0));
                auto location = player_start->GetActorLocation();
                context->RequestNewWorldOrigin(FIntVector(location.X, location.Y, location.Z));
                success = true;
                break;
            }
        }
    }
    return success;
}

std::vector<UPrimitiveComponent*> UAirBlueprintLib::getPhysicsComponents(AActor* actor)
{
    std::vector<UPrimitiveComponent*> phys_comps;
    TInlineComponentArray<UPrimitiveComponent*> components;
    actor->GetComponents(components);

    for (UPrimitiveComponent* component : components) {
        if (component->IsSimulatingPhysics())
            phys_comps.push_back(component);
    }

    return phys_comps;
}

void UAirBlueprintLib::resetSimulatePhysics(AActor* actor)
{
    TInlineComponentArray<UPrimitiveComponent*> components;
    actor->GetComponents(components);

    for (UPrimitiveComponent* component : components) {
        if (component->IsSimulatingPhysics()) {
            component->SetSimulatePhysics(false);
            component->SetSimulatePhysics(true);
        }
    }
}

void UAirBlueprintLib::enableViewportRendering(AActor* context, bool enable)
{
    // Enable/disable primary viewport rendering flag
    auto* viewport = context->GetWorld()->GetGameViewport();
    if (!viewport)
        return;

    if (!enable) {
        // This disables rendering of the main viewport in the same way as the
        // console command "show rendering" would do.
        viewport->EngineShowFlags.SetRendering(false);

        // When getting an image through the API, the image is produced after the render
        // thread has finished rendering the current and the subsequent frame. This means
        // that the frame rate for obtaining images through the API is only half as high as
        // it could be, since only every other image is actually captured. We work around
        // this by telling the viewport to flush the rendering queue at the end of each
        // drawn frame so that it executes our render request at that point already.
        // Do this only if the main viewport is not being rendered anyway in case there are
        // any adverse performance effects during main rendering.

        // TODO: Validate framerate of sensor data when the NoDisplay setting is turned on.
    }
    else {
        viewport->EngineShowFlags.SetRendering(true);
    }
}

void UAirBlueprintLib::OnBeginPlay()
{
    image_wrapper_module_ = &FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
}

void UAirBlueprintLib::OnEndPlay()
{
    //nothing to do for now
    image_wrapper_module_ = nullptr;
}

IImageWrapperModule* UAirBlueprintLib::getImageWrapperModule()
{
    return image_wrapper_module_;
}

void UAirBlueprintLib::setLogMessagesVisibility(bool is_visible)
{
    log_messages_hidden_ = !is_visible;

    // if hidden, clear any existing messages
    if (!is_visible && GEngine)
        GEngine->ClearOnScreenDebugMessages();
}

void UAirBlueprintLib::LogMessage(const FString& prefix, const FString& suffix, LogDebugLevel level, float persist_sec)
{
    if (log_messages_hidden_)
        return;

    static TMap<FString, int> loggingKeys;
    static int counter = 1;

    int key = loggingKeys.FindOrAdd(prefix);
    if (key == 0) {
        key = counter++;
        loggingKeys[prefix] = key;
    }

    FColor color;
    switch (level) {
    case LogDebugLevel::Informational:
        color = FColor(147, 231, 237);
        //UE_LOG(LogTemp, Log, TEXT("%s%s"), *prefix, *suffix);
        break;
    case LogDebugLevel::Success:
        color = FColor(156, 237, 147);
        //UE_LOG(LogTemp, Log, TEXT("%s%s"), *prefix, *suffix);
        break;
    case LogDebugLevel::Failure:
        color = FColor(237, 147, 168);
        //UE_LOG(LogAirSim, Error, TEXT("%s%s"), *prefix, *suffix);
        break;
    case LogDebugLevel::Unimportant:
        color = FColor(237, 228, 147);
        //UE_LOG(LogTemp, Verbose, TEXT("%s%s"), *prefix, *suffix);
        break;
    default:
        color = FColor::Black;
        break;
    }
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(key, persist_sec, color, prefix + suffix);
    }
    //GEngine->AddOnScreenDebugMessage(key + 10, 60.0f, color, FString::FromInt(key));
}

void UAirBlueprintLib::GenerateAssetRegistryMap(const UObject* context, TMap<FString, FAssetData>& asset_map)
{
    UAirBlueprintLib::RunCommandOnGameThread([context, &asset_map]() {
        FARFilter Filter;
        Filter.ClassPaths.Add(UStaticMesh::StaticClass()->GetClassPathName());
        Filter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());
        Filter.bRecursivePaths = true;

        auto world = context->GetWorld();
        TArray<FAssetData> AssetData;

        // Find mesh in /Game and /AirSim asset registry. When more plugins are added this function will have to change
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
        AssetRegistryModule.Get().GetAssets(Filter, AssetData);

        UObject* LoadObject = NULL;
        for (const auto& asset : AssetData) {
            FString asset_name = asset.AssetName.ToString();
            asset_map.Add(asset_name, asset);
        }

        LogMessageString("Asset database ready", "!", LogDebugLevel::Informational);
    },
                                             true);
}

void UAirBlueprintLib::GenerateActorMap(const UObject* context, TMap<FString, AActor*>& scene_object_map)
{
    auto world = context->GetWorld();
    for (TActorIterator<AActor> actorIterator(world); actorIterator; ++actorIterator) {
        AActor* actor = *actorIterator;
        FString name = *actor->GetName();

        scene_object_map.Add(name, actor);
    }
}

void UAirBlueprintLib::setUnrealClockSpeed(const AActor* context, float clock_speed)
{
    UAirBlueprintLib::RunCommandOnGameThread([context, clock_speed]() {
        auto* world_settings = context->GetWorldSettings();
        if (world_settings)
            world_settings->SetTimeDilation(clock_speed);
        else
            LogMessageString("Failed:", "WorldSettings was nullptr", LogDebugLevel::Failure);
    }, true);
}

float UAirBlueprintLib::getUnrealClockSpeed(const AActor* context)
{
	UAirBlueprintLib::RunCommandOnGameThread([context]() {
		auto* world_settings = context->GetWorldSettings();
		if (world_settings){
			return world_settings->TimeDilation;
        }
		else{
            LogMessageString("Failed:", "WorldSettings was nullptr", LogDebugLevel::Failure);
			return 1.0f;
        }

	}, true);
	return 1.0f;
}

float UAirBlueprintLib::GetWorldToMetersScale(const AActor* context)
{
    float w2m = 100.f;
    UWorld* w = context->GetWorld();
    if (w != nullptr) {
        AWorldSettings* ws = w->GetWorldSettings();
        if (ws != nullptr) {
            w2m = ws->WorldToMeters;
        }
    }
    return w2m;
}

template <typename T>
T* UAirBlueprintLib::GetActorComponent(AActor* actor, FString name)
{
    TArray<T*> components;
    actor->GetComponents(components);
    T* found = nullptr;
    for (T* component : components) {
        if (component->GetName().Compare(name) == 0) {
            found = component;
            break;
        }
    }
    return found;
}
template UChildActorComponent* UAirBlueprintLib::GetActorComponent(AActor*, FString);
template USceneCaptureComponent2D* UAirBlueprintLib::GetActorComponent(AActor*, FString);
template UStaticMeshComponent* UAirBlueprintLib::GetActorComponent(AActor*, FString);
template URotatingMovementComponent* UAirBlueprintLib::GetActorComponent(AActor*, FString);
template UCameraComponent* UAirBlueprintLib::GetActorComponent(AActor*, FString);
template UDetectionComponent* UAirBlueprintLib::GetActorComponent(AActor*, FString);
template UCineCameraComponent* UAirBlueprintLib::GetActorComponent(AActor*, FString);

bool UAirBlueprintLib::IsInGameThread()
{
    return ::IsInGameThread();
}

void UAirBlueprintLib::RunCommandOnGameThread(TFunction<void()> InFunction, bool wait, const TStatId InStatId)
{
    if (IsInGameThread())
        InFunction();
    else {
        FGraphEventRef task = FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(InFunction), InStatId, nullptr, ENamedThreads::GameThread);
        if (wait)
            FTaskGraphInterface::Get().WaitUntilTaskCompletes(task);
    }
}

template <>
std::string UAirBlueprintLib::GetMeshName<USkinnedMeshComponent>(USkinnedMeshComponent* mesh)
{
    if (mesh->GetOwner())
        return std::string(TCHAR_TO_UTF8(*(mesh->GetOwner()->GetName())));
    else
        return ""; // std::string(TCHAR_TO_UTF8(*(UKismetSystemLibrary::GetDisplayName(mesh))));
}


std::string UAirBlueprintLib::GetMeshName(ALandscapeProxy* mesh)
{
    return std::string(TCHAR_TO_UTF8(*(mesh->GetName())));
}

void UAirBlueprintLib::InitializeMeshStencilIDs(bool ignore_existing, FString material_list)
{
    std::string materialListString = std::string(TCHAR_TO_UTF8(*material_list));
    std::map< std::string, int> materialMap;


    std::istringstream iss(materialListString);
    std::string line, word;
    int stencil_index = 1;

    while (std::getline(iss, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        materialMap.emplace(row[0], stencil_index);
        stencil_index = stencil_index + 1;
    }

    for (TObjectIterator<UStaticMeshComponent> comp; comp; ++comp)
    {
        InitializeObjectStencilID(*comp, materialMap, ignore_existing);
    }
    for (TObjectIterator<USkinnedMeshComponent> comp; comp; ++comp)
    {
        InitializeObjectStencilID(*comp, materialMap, ignore_existing);
    }
    for (TObjectIterator<ALandscapeProxy> comp; comp; ++comp)
    {
        InitializeObjectStencilID(*comp, materialMap, ignore_existing);
    }
}

bool UAirBlueprintLib::SetMeshStencilID(const std::string& mesh_name, int object_id,
                                        bool is_name_regex)
{
    std::regex name_regex;

    if (is_name_regex)
        name_regex.assign(mesh_name, std::regex_constants::icase);

    int changes = 0;
    for (TObjectIterator<UStaticMeshComponent> comp; comp; ++comp) {
        SetObjectStencilIDIfMatch(*comp, object_id, mesh_name, is_name_regex, name_regex, changes);
    }
    for (TObjectIterator<USkinnedMeshComponent> comp; comp; ++comp) {
        SetObjectStencilIDIfMatch(*comp, object_id, mesh_name, is_name_regex, name_regex, changes);
    }
    for (TObjectIterator<ALandscapeProxy> comp; comp; ++comp) {
        SetObjectStencilIDIfMatch(*comp, object_id, mesh_name, is_name_regex, name_regex, changes);
    }

    return changes > 0;
}

int UAirBlueprintLib::GetMeshStencilID(const std::string& mesh_name)
{
    // Takes a UStaticMeshComponent, USkinnedMeshComponent or ALandscapeProxy and returns their custom stencil ID if
    // their meshes's name or their owner's name (depending on the naming method in mesh_naming_method_) equals mesh_name
    auto getCustomStencilForMesh = [&mesh_name](auto mesh) -> int {
        const std::string component_mesh_name = common_utils::Utils::toLower(GetMeshName(mesh));
        if (component_mesh_name.compare(mesh_name) == 0) {
            return mesh->CustomDepthStencilValue;
        }
        return -1;
    };

    for (TObjectIterator<UStaticMeshComponent> comp; comp; ++comp) {
        int id = getCustomStencilForMesh(*comp);
        if (id != -1)
            return id;
    }
    for (TObjectIterator<USkinnedMeshComponent> comp; comp; ++comp) {
        int id = getCustomStencilForMesh(*comp);
        if (id != -1)
            return id;
    }
    for (TObjectIterator<ALandscapeProxy> comp; comp; ++comp) {
        int id = getCustomStencilForMesh(*comp);
        if (id != -1)
            return id;
    }

    return -1;
}

std::vector<std::string> UAirBlueprintLib::ListMatchingActorsOriginal(const UObject* context, const std::string& name_regex)
{
    std::vector<std::string> results;
    auto world = context->GetWorld();
    std::regex compiledRegex(name_regex, std::regex::optimize);
    for (TActorIterator<AActor> actorIterator(world); actorIterator; ++actorIterator) {
        AActor* actor = *actorIterator;
        auto name = std::string(TCHAR_TO_UTF8(*actor->GetName()));
        bool match = std::regex_match(name, compiledRegex);
        if (match)
            results.push_back(name);
    }
    return results;
}

std::vector<std::string> UAirBlueprintLib::ListMatchingActors(const UObject *context, const std::string& name_regex)
{
    std::vector<std::string> results;
    auto world = context->GetWorld();
    std::regex compiledRegex(name_regex, std::regex::optimize);
    for (TActorIterator<AActor> actorIterator(world); actorIterator; ++actorIterator)
    {
        AActor *actor = *actorIterator;
		TArray<UMeshComponent*> paintable_components;
		actor->GetComponents<UMeshComponent>(paintable_components);
		int index = 0;
		for (auto component : paintable_components)
		{
			FString mesh_name;
			if (paintable_components.Num() == 1) {
				if (UStaticMeshComponent* staticmesh_component = Cast<UStaticMeshComponent>(component)) {
					if (actor->GetParentActor()) {
						mesh_name = staticmesh_component->GetStaticMesh()->GetName();
						mesh_name.Append("_");
						mesh_name.Append(FString::FromInt(0));
						mesh_name.Append("_");
						if (actor->GetRootComponent()->GetAttachParent()) {
							mesh_name.Append(actor->GetRootComponent()->GetAttachParent()->GetName());
							mesh_name.Append("_");
						}
						mesh_name.Append(actor->GetParentActor()->GetName());
					}
					else {
						mesh_name = actor->GetName();
					}
				}
				if (USkinnedMeshComponent*  skinnedmesh_component = Cast<USkinnedMeshComponent>(component)) {
					mesh_name = actor->GetName();
				}
			}
			else {
				if (UStaticMeshComponent* staticmesh_component = Cast<UStaticMeshComponent>(component)) {
					mesh_name = staticmesh_component->GetStaticMesh()->GetName();
					mesh_name.Append("_");
					mesh_name.Append(FString::FromInt(index));
					mesh_name.Append("_");
					if (actor->GetParentActor()) {
						if (actor->GetRootComponent()->GetAttachParent()) {
							mesh_name.Append(actor->GetRootComponent()->GetAttachParent()->GetName());
							mesh_name.Append("_");
						}
						mesh_name.Append(actor->GetParentActor()->GetName());
					}
					else {
						mesh_name.Append(actor->GetName());
					}
				}
				if (USkinnedMeshComponent*  skinnedmesh_component = Cast<USkinnedMeshComponent>(component)) {
					mesh_name = actor->GetName();
				}
				index++;
			}
			auto name = std::string(TCHAR_TO_UTF8(*mesh_name));
			bool match = std::regex_match(name, compiledRegex);
			if (match)
				results.push_back(name);
		}
    }
    return results;
}

std::vector<msr::airlib::MeshPositionVertexBuffersResponse> UAirBlueprintLib::GetStaticMeshComponents()
{
    std::vector<msr::airlib::MeshPositionVertexBuffersResponse> meshes;
    int num_meshes = 0;
    for (TObjectIterator<UStaticMeshComponent> comp; comp; ++comp) {
        *comp;

        std::string name = common_utils::Utils::toLower(GetMeshName(*comp));
        //The skybox is ignored here as it is huge, and really is of no use to the end user typically. Also the associated meshes with the cameras
        if (name == "" || common_utils::Utils::startsWith(name, "default_") || common_utils::Utils::startsWith(name, "sky") || common_utils::Utils::startsWith(name, "camera")) {
            continue;
        }

        //Various checks if there is even a valid mesh
        if (!comp->GetStaticMesh()) continue;
        if (!comp->GetStaticMesh()->HasValidRenderData()) continue;
#if ((ENGINE_MAJOR_VERSION > 4) || (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 27))
        if (comp->GetStaticMesh()->GetRenderData()->LODResources.Num() == 0) continue;
#else
        if (comp->GetStaticMesh()->RenderData->LODResources.Num() == 0) continue;
#endif

        msr::airlib::MeshPositionVertexBuffersResponse mesh;
        mesh.name = name;

        FVector pos = comp->GetComponentLocation();
        FQuat att = comp->GetComponentQuat();
        mesh.position[0] = pos.X;
        mesh.position[1] = pos.Y;
        mesh.position[2] = pos.Z;
        mesh.orientation.w() = att.W;
        mesh.orientation.x() = att.X;
        mesh.orientation.y() = att.Y;
        mesh.orientation.z() = att.Z;

#if ((ENGINE_MAJOR_VERSION > 4) || (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 27))
        FPositionVertexBuffer* vertex_buffer = &comp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
#else
        FPositionVertexBuffer* vertex_buffer = &comp->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
#endif
        if (vertex_buffer) {
            const int32 vertex_count = vertex_buffer->VertexBufferRHI->GetSize();
            TArray<FVector> vertices;
            vertices.SetNum(vertex_count);
            FVector* data = vertices.GetData();

            ENQUEUE_RENDER_COMMAND(GetVertexBuffer)
            (
                [vertex_buffer, data](FRHICommandListImmediate& RHICmdList) {
                    FVector* indices = (FVector*)RHILockBuffer(vertex_buffer->VertexBufferRHI, 0, vertex_buffer->VertexBufferRHI->GetSize(), RLM_ReadOnly);
                    memcpy(data, indices, vertex_buffer->VertexBufferRHI->GetSize());
                    RHIUnlockBuffer(vertex_buffer->VertexBufferRHI);
                });

#if ((ENGINE_MAJOR_VERSION > 4) || (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 27))
            FStaticMeshLODResources& lod = comp->GetStaticMesh()->GetRenderData()->LODResources[0];
#else
            FStaticMeshLODResources& lod = comp->GetStaticMesh()->RenderData->LODResources[0];
#endif
            FRawStaticIndexBuffer* IndexBuffer = &lod.IndexBuffer;
            int num_indices = IndexBuffer->IndexBufferRHI->GetSize() / IndexBuffer->IndexBufferRHI->GetStride();

            if (IndexBuffer->IndexBufferRHI->GetStride() == 2) {
                TArray<uint16_t> indices_vec;
                indices_vec.SetNum(num_indices);

                uint16_t* data_ptr = indices_vec.GetData();

                ENQUEUE_RENDER_COMMAND(GetIndexBuffer)
                (
                    [IndexBuffer, data_ptr](FRHICommandListImmediate& RHICmdList) {
                        uint16_t* indices = (uint16_t*)RHILockBuffer(IndexBuffer->IndexBufferRHI, 0, IndexBuffer->IndexBufferRHI->GetSize(), RLM_ReadOnly);
                        memcpy(data_ptr, indices, IndexBuffer->IndexBufferRHI->GetSize());
                        RHIUnlockBuffer(IndexBuffer->IndexBufferRHI);
                    });

                //Need to force the render command to go through cause on the next iteration the buffer no longer exists
                FlushRenderingCommands();

                mesh.indices.resize(num_indices);
                for (int idx = 0; idx < num_indices; ++idx) {
                    mesh.indices[idx] = indices_vec[idx];
                }
            }

            else { //stride ==4
                TArray<uint32_t> indices_vec;
                indices_vec.SetNum(num_indices);

                uint32_t* data_ptr = indices_vec.GetData();

                ENQUEUE_RENDER_COMMAND(GetIndexBuffer)
                (
                    [IndexBuffer, data_ptr](FRHICommandListImmediate& RHICmdList) {
                        uint32_t* indices = (uint32_t*)RHILockBuffer(IndexBuffer->IndexBufferRHI, 0, IndexBuffer->IndexBufferRHI->GetSize(), RLM_ReadOnly);
                        memcpy(data_ptr, indices, IndexBuffer->IndexBufferRHI->GetSize());
                        RHIUnlockBuffer(IndexBuffer->IndexBufferRHI);
                    });

                FlushRenderingCommands();

                mesh.indices.resize(num_indices);
                for (int idx = 0; idx < num_indices; ++idx) {
                    mesh.indices[idx] = indices_vec[idx];
                }
            }

            //Unreal stores more vertices than triangles. So here we find the highest referenced vertex and ignore any after that
            auto result_iter = std::max_element(mesh.indices.begin(), mesh.indices.end());
            auto max_triangle_index = std::distance(mesh.indices.begin(), result_iter);

            mesh.vertices.resize(max_triangle_index * 3);
            int aligned_index = 0;
            FTransform transform = comp->GetComponentTransform();
            for (int vertex_idx = 0; vertex_idx < max_triangle_index; ++vertex_idx) {
                FVector transformed_vec = pos + transform.TransformVector(vertices[vertex_idx]);
                mesh.vertices[aligned_index++] = transformed_vec.X;
                mesh.vertices[aligned_index++] = transformed_vec.Y;
                mesh.vertices[aligned_index++] = transformed_vec.Z;
            }
        }

        meshes.push_back(mesh);
    }

    return meshes;
}

TArray<FName> UAirBlueprintLib::ListWorldsInRegistry()
{
    FARFilter Filter;
    Filter.ClassNames.Add(UWorld::StaticClass()->GetFName());
    Filter.bRecursivePaths = true;

    TArray<FAssetData> AssetData;
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    AssetRegistryModule.Get().GetAssets(Filter, AssetData);

    TArray<FName> WorldNames;
    for (auto asset : AssetData)
        WorldNames.Add(asset.AssetName);
    return WorldNames;
}

UObject* UAirBlueprintLib::GetMeshFromRegistry(const std::string& load_object)
{
    FARFilter Filter;
    Filter.ClassNames.Add(UStaticMesh::StaticClass()->GetFName());
    Filter.bRecursivePaths = true;

    TArray<FAssetData> AssetData;
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    AssetRegistryModule.Get().GetAssets(Filter, AssetData);

    UObject* LoadObject = NULL;
    for (auto asset : AssetData) {
        UE_LOG(LogTemp, Log, TEXT("Asset path: %s"), *asset.PackagePath.ToString());
        if (asset.AssetName == FName(load_object.c_str())) {
            LoadObject = asset.GetAsset();
            break;
        }
    }
    return LoadObject;
}

bool UAirBlueprintLib::RunConsoleCommand(const AActor* context, const FString& command)
{
    auto* playerController = UGameplayStatics::GetPlayerController(context->GetWorld(), 0);
    ;
    if (playerController != nullptr)
        playerController->ConsoleCommand(command, true);
    return playerController != nullptr;
}

bool UAirBlueprintLib::HasObstacle(const AActor* actor, const FVector& start, const FVector& end, const AActor* ignore_actor, ECollisionChannel collision_channel)
{
    FCollisionQueryParams trace_params;
    trace_params.AddIgnoredActor(actor);
    if (ignore_actor != nullptr)
        trace_params.AddIgnoredActor(ignore_actor);

    return actor->GetWorld()->LineTraceTestByChannel(start, end, collision_channel, trace_params);
}

bool UAirBlueprintLib::GetObstacle(const AActor* actor, const FVector& start, const FVector& end,
                                   FHitResult& hit, const AActor* ignore_actor, ECollisionChannel collision_channel)
{
	hit = FHitResult(ForceInit);

	FCollisionQueryParams trace_params;
	if (ignore_actor != nullptr)
		trace_params.AddIgnoredActor(ignore_actor);

	return actor->GetWorld()->LineTraceSingleByChannel(hit, start, end, collision_channel, trace_params);
}

bool UAirBlueprintLib::GetObstacleAdv(const AActor* actor, const FVector& start, const FVector& end,
	FHitResult& hit, TArray<AActor*>& ignore_actors, ECollisionChannel collision_channel, bool trace_complex, bool get_material)
{
	hit = FHitResult(ForceInit);

	FCollisionQueryParams trace_params;
	trace_params.bReturnPhysicalMaterial = get_material;
	trace_params.bTraceComplex = trace_complex;

	trace_params.AddIgnoredActors(ignore_actors);

	return actor->GetWorld()->LineTraceSingleByChannel(hit, start, end, collision_channel, trace_params);
}

bool UAirBlueprintLib::GetLastObstaclePosition(const AActor* actor, const FVector& start, const FVector& end,
                                               FHitResult& hit, const AActor* ignore_actor, ECollisionChannel collision_channel)
{
    TArray<FHitResult> hits;

    FCollisionQueryParams trace_params;
    trace_params.AddIgnoredActor(actor);
    if (ignore_actor != nullptr)
        trace_params.AddIgnoredActor(ignore_actor);

    bool has_hit = actor->GetWorld()->LineTraceMultiByChannel(hits, start, end, collision_channel, trace_params);

    if (hits.Num())
        hit = hits.Last(0);

    return has_hit;
}

void UAirBlueprintLib::FollowActor(AActor* follower, const AActor* followee, const FVector& offset, bool fixed_z, float fixed_z_val)
{
    //can we see followee?
    FHitResult hit;
    if (followee == nullptr) {
        return;
    }
    FVector actor_location = followee->GetActorLocation() + FVector(0, 0, 4);
    FVector next_location = actor_location + offset;
    if (fixed_z)
        next_location.Z = fixed_z_val;

    if (GetObstacle(follower, next_location, actor_location, hit, followee, ECC_Visibility)) {
        next_location = hit.ImpactPoint + offset;

        if (GetObstacle(follower, next_location, actor_location, hit, followee, ECC_Visibility)) {
            float next_z = next_location.Z;
            next_location = hit.ImpactPoint - offset;
            next_location.Z = next_z;
        }
    }

    float dist = (follower->GetActorLocation() - next_location).Size();
    float offset_dist = offset.Size();
    float dist_offset = (dist - offset_dist) / offset_dist;
    float lerp_alpha = common_utils::Utils::clip((dist_offset * dist_offset) * 0.01f + 0.01f, 0.0f, 1.0f);
    next_location = FMath::Lerp(follower->GetActorLocation(), next_location, lerp_alpha);
    follower->SetActorLocation(next_location);

    FRotator next_rot = UKismetMathLibrary::FindLookAtRotation(follower->GetActorLocation(), followee->GetActorLocation());
    next_rot = FMath::Lerp(follower->GetActorRotation(), next_rot, 0.5f);
    follower->SetActorRotation(next_rot);
}

int UAirBlueprintLib::RemoveAxisBinding(const FInputAxisKeyMapping& axis, FInputAxisBinding* axis_binding, AActor* actor)
{
    if (axis_binding != nullptr && actor != nullptr) {
        APlayerController* controller = actor->GetWorld()->GetFirstPlayerController();

        //remove mapping
        int found_mapping_index = -1, cur_mapping_index = -1;
        for (const auto& axis_arr : controller->PlayerInput->AxisMappings) {
            ++cur_mapping_index;
            if (axis_arr.AxisName == axis.AxisName && axis_arr.Key == axis.Key) {
                found_mapping_index = cur_mapping_index;
                break;
            }
        }
        if (found_mapping_index >= 0)
            controller->PlayerInput->AxisMappings.RemoveAt(found_mapping_index);

        //removing binding
        int found_binding_index = -1, cur_binding_index = -1;
        for (const auto& axis_arr : controller->InputComponent->AxisBindings) {
            ++cur_binding_index;
            if (axis_arr.AxisName == axis_binding->AxisName) {
                found_binding_index = cur_binding_index;
                break;
            }
        }
        if (found_binding_index >= 0)
            controller->InputComponent->AxisBindings.RemoveAt(found_binding_index);

        return found_binding_index;
    }
    else
        return -1;
}

float UAirBlueprintLib::GetDisplayGamma()
{
    return GEngine->DisplayGamma;
}

void UAirBlueprintLib::EnableInput(AActor* actor)
{
    actor->EnableInput(actor->GetWorld()->GetFirstPlayerController());
}

UObject* UAirBlueprintLib::LoadObject(const std::string& name)
{
    FString str(name.c_str());
    UObject* obj = StaticLoadObject(UObject::StaticClass(), nullptr, *str);
    if (obj == nullptr) {
        std::string msg = "Failed to load asset object - " + name;
        FString fmsg(msg.c_str());
        LogMessage(TEXT("Load: "), fmsg, LogDebugLevel::Failure);
        throw std::invalid_argument(msg);
    }
    return obj;
}

UClass* UAirBlueprintLib::LoadClass(const std::string& name)
{
    FString str(name.c_str());
    UClass* cls = StaticLoadClass(UObject::StaticClass(), nullptr, *str);
    if (cls == nullptr) {
        std::string msg = "Failed to load asset class - " + name;
        FString fmsg(msg.c_str());
        LogMessage(TEXT("Load: "), fmsg, LogDebugLevel::Failure);
        throw std::invalid_argument(msg);
    }
    return cls;
}

void UAirBlueprintLib::CompressImageArray(int32 width, int32 height, const TArray<FColor>& src, TArray<uint8>& dest)
{
    TArray<FColor> MutableSrcData = src;

    // PNGs are saved as RGBA but FColors are stored as BGRA. An option to swap the order upon compression may be added at
    // some point. At the moment, manually swapping Red and Blue
    for (int32 Index = 0; Index < width * height; Index++) {
        uint8 TempRed = MutableSrcData[Index].R;
        MutableSrcData[Index].R = MutableSrcData[Index].B;
        MutableSrcData[Index].B = TempRed;
        MutableSrcData[Index].A = 255;
    }

    FObjectThumbnail TempThumbnail;
    TempThumbnail.SetImageSize(width, height);
    TArray<uint8>& ThumbnailByteArray = TempThumbnail.AccessImageData();

    // Copy scaled image into destination thumb
    int32 MemorySize = width * height * sizeof(FColor);
    ThumbnailByteArray.AddUninitialized(MemorySize);
    FMemory::Memcpy(ThumbnailByteArray.GetData(), MutableSrcData.GetData(), MemorySize);

    // Compress data - convert into a .png
    CompressUsingImageWrapper(ThumbnailByteArray, width, height, dest);
    ;
}

bool UAirBlueprintLib::CompressUsingImageWrapper(const TArray<uint8>& uncompressed, const int32 width, const int32 height, TArray<uint8>& compressed)
{
    bool bSucceeded = false;
    compressed.Reset();
    if (uncompressed.Num() > 0) {
        IImageWrapperModule* ImageWrapperModule = UAirBlueprintLib::getImageWrapperModule();
        TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule->CreateImageWrapper(EImageFormat::PNG);
        if (ImageWrapper.IsValid() && ImageWrapper->SetRaw(&uncompressed[0], uncompressed.Num(), width, height, ERGBFormat::RGBA, 8)) {
            compressed = ImageWrapper->GetCompressed();
            bSucceeded = true;
        }
    }

    return bSucceeded;
}
