// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "GameFramework/Actor.h"
#include "Components/InputComponent.h"
#include "EngineUtils.h"
#include "Engine/Blueprint.h"
#include "GameFramework/PlayerInput.h"
#include "IImageWrapperModule.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetRegistry/AssetData.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/MeshComponent.h"
#include "StaticMeshResources.h"
#include "Rendering/PositionVertexBuffer.h"
#include "LandscapeProxy.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "Engine/World.h"
#include "Runtime/Landscape/Classes/LandscapeComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Core/Public/HAL/FileManager.h"
#include "common/AirSimSettings.hpp"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include <string>
#include <regex>
#include "AirBlueprintLib.generated.h"

UENUM(BlueprintType)
enum class LogDebugLevel : uint8
{
    Informational UMETA(DisplayName = "Informational"),
    Success UMETA(DisplayName = "Success"),
    Failure UMETA(DisplayName = "Failure"),
    Unimportant UMETA(DisplayName = "Unimportant")
};

/**
*
*/
UCLASS()
class UAirBlueprintLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static void OnBeginPlay();
    static void OnEndPlay();
    static void LogMessageString(const std::string& prefix, const std::string& suffix, LogDebugLevel level, float persist_sec = 60);
    UFUNCTION(BlueprintCallable, Category = "Utils")
    static void LogMessage(const FString& prefix, const FString& suffix, LogDebugLevel level, float persist_sec = 60);
    static float GetWorldToMetersScale(const AActor* context);
    template <typename T>
    static T* GetActorComponent(AActor* actor, FString name);

    template <typename T>
    static T* FindActor(const UObject* context, FString name)
    {
        FName name_n = FName(*name);
        for (TActorIterator<AActor> It(context->GetWorld(), T::StaticClass()); It; ++It) {
            AActor* Actor = *It;
            if (!Actor->IsPendingKill() && (Actor->ActorHasTag(name_n) || Actor->GetName().Compare(name) == 0)) {
                return static_cast<T*>(Actor);
            }
        }
        return nullptr;
    }

    template <typename T>
    static void FindAllActor(const UObject* context, TArray<AActor*>& foundActors)
    {
        UGameplayStatics::GetAllActorsOfClass(context, T::StaticClass(), foundActors);
    }

    static std::vector<std::string> ListMatchingActorsOriginal(const UObject* context, const std::string& name_regex);
    static std::vector<std::string> ListMatchingActors(const UObject *context, const std::string& name_regex);
    UFUNCTION(BlueprintCallable, Category = "AirSim|LevelAPI")
    static bool loadLevel(UObject* context, const FString& level_name);
    UFUNCTION(BlueprintCallable, Category = "AirSim|LevelAPI")
    static bool spawnPlayer(UWorld* context);
    UFUNCTION(BlueprintPure, Category = "AirSim|LevelAPI")
    static TArray<FName> ListWorldsInRegistry();
    static UObject* GetMeshFromRegistry(const std::string& load_object);
    static void GenerateAssetRegistryMap(const UObject* context, TMap<FString, FAssetData>& asset_map);
    static void GenerateActorMap(const UObject* context, TMap<FString, AActor*>& scene_object_map);

    UFUNCTION(BlueprintCallable, Category = "AirSim")
    static bool RunConsoleCommand(const AActor* context, const FString& command);

    static bool HasObstacle(const AActor* actor, const FVector& start, const FVector& end,
                            const AActor* ignore_actor = nullptr, ECollisionChannel collision_channel = ECC_Visibility);
    static bool GetObstacle(const AActor* actor, const FVector& start, const FVector& end,
                            FHitResult& hit, const AActor* ignore_actor = nullptr, ECollisionChannel collision_channel = ECC_Visibility);
    static bool GetObstacleAdv(const AActor* actor, const FVector& start, const FVector& end,
		                       FHitResult& hit, TArray<AActor*>& ignore_actors, ECollisionChannel collision_channel = ECC_Visibility, bool trace_complex = false, bool get_material = false);
    static bool GetLastObstaclePosition(const AActor* actor, const FVector& start, const FVector& end,
                                        FHitResult& hit, const AActor* ignore_actor = nullptr, ECollisionChannel collision_channel = ECC_Visibility);
    static void FollowActor(AActor* follower, const AActor* followee, const FVector& offset, bool fixed_z = false, float fixed_z_val = 2.0f);

    static bool SetMeshStencilID(const std::string& mesh_name, int object_id,
                                 bool is_name_regex = false);
    static int GetMeshStencilID(const std::string& mesh_name);
    static void InitializeMeshStencilIDs(bool ignore_existing, FString material_list);

    static bool IsInGameThread();

	template<class T>
	static std::string GetMeshName(T* mesh)
	{
		if (mesh->GetOwner())
		{
			// For foliage actors, need to use mesh's name in order to differentiate different meshes from each other.
			// Otherwise, all items placed with the foliage actor will get the same ID.
			auto owner = mesh->GetOwner();
			if (owner->GetName().StartsWith("InstancedFoliageActor"))
			{
				FString meshName = mesh->GetName();

				// It is expected that the user will create a blueprint class that starts with "IFA_" for each of the classes they want to differentiate.
				// Unreal adds a _C_ into the name for blueprint created classes, which messes up the hash. Remove it as well.
				if (meshName.StartsWith(TEXT("IFA_")))
				{
					meshName = meshName.Replace(TEXT("IFA_"), TEXT("")).Replace(TEXT("_C_"), TEXT(""));
				}

				return std::string(TCHAR_TO_UTF8(*(meshName)));
			}

			return std::string(TCHAR_TO_UTF8(*(owner->GetName())));
		}
		else
			return ""; //std::string(TCHAR_TO_UTF8(*(UKismetSystemLibrary::GetDisplayName(mesh))));
	}

    static std::string GetMeshName(ALandscapeProxy* mesh);

    template <class UserClass>
    static FInputActionBinding& BindActionToKey(const FName action_name, const FKey in_key, UserClass* actor,
                                                typename FInputActionHandlerSignature::TUObjectMethodDelegate<UserClass>::FMethodPtr func, bool on_press_or_release = false,
                                                bool shift_key = false, bool control_key = false, bool alt_key = false, bool command_key = false)
    {
        FInputActionKeyMapping action(action_name, in_key, shift_key, control_key, alt_key, command_key);

        APlayerController* controller = actor->GetWorld()->GetFirstPlayerController();

        controller->PlayerInput->AddActionMapping(action);
        return controller->InputComponent->BindAction(action_name, on_press_or_release ? IE_Pressed : IE_Released, actor, func);
    }

    template <class UserClass>
    static FInputAxisBinding& BindAxisToKey(const FName axis_name, const FKey in_key, AActor* actor, UserClass* obj,
                                            typename FInputAxisHandlerSignature::TUObjectMethodDelegate<UserClass>::FMethodPtr func)
    {
        FInputAxisKeyMapping axis(axis_name, in_key);

        return UAirBlueprintLib::BindAxisToKey(axis, actor, obj, func);
    }

    template <class UserClass>
    static FInputAxisBinding& BindAxisToKey(const FInputAxisKeyMapping& axis, AActor* actor, UserClass* obj,
                                            typename FInputAxisHandlerSignature::TUObjectMethodDelegate<UserClass>::FMethodPtr func)
    {
        APlayerController* controller = actor->GetWorld()->GetFirstPlayerController();

        controller->PlayerInput->AddAxisMapping(axis);
        return controller->InputComponent->BindAxis(axis.AxisName, obj, func);
    }

    static int RemoveAxisBinding(const FInputAxisKeyMapping& axis, FInputAxisBinding* axis_binding, AActor* actor);

    static void EnableInput(AActor* actor);

    static void RunCommandOnGameThread(TFunction<void()> InFunction, bool wait = false, const TStatId InStatId = TStatId());

    static float GetDisplayGamma();

    static EAppReturnType::Type ShowMessage(EAppMsgType::Type MessageType, const std::string& message, const std::string& title);

    static bool getLogMessagesHidden()
    {
        return log_messages_hidden_;
    }
    static void setLogMessagesVisibility(bool is_visible);

    static void enableWorldRendering(AActor* context, bool enable);
    static void DrawCoordinateSystem(const UWorld* InWorld, FVector const& AxisLoc, FRotator const& AxisRot, float Scale, bool bPersistentLines = false, float LifeTime = -1.f, uint8 DepthPriority = 0, float Thickness = 0.f);
	static void DrawLine(const UWorld* InWorld, FVector const& LineStart, FVector const& LineEnd, FColor const& Color, bool bPersistentLines = false, float LifeTime = -1.f, uint8 DepthPriority = 0, float Thickness = 0.f);
	static void DrawPoint(const UWorld* InWorld, FVector const& Position, float Size, FColor const& Color, bool bPersistentLines = false, float LifeTime = -1.f, uint8 DepthPriority = 0);
	static void DrawCircle(const UWorld* InWorld, const FMatrix& TransformMatrix, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.f, uint8 DepthPriority = 0, float Thickness = 0.f, bool bDrawAxis = true);
	static void DrawCircle(const UWorld* InWorld, FVector Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.f, uint8 DepthPriority = 0, float Thickness = 0.f, FVector YAxis = FVector(0.f, 1.f, 0.f), FVector ZAxis = FVector(0.f, 0.f, 1.f), bool bDrawAxis = true);
    static void enableViewportRendering(AActor* context, bool enable);
    static void setSimulatePhysics(AActor* actor, bool simulate_physics);
    static void resetSimulatePhysics(AActor* actor);
    static std::vector<UPrimitiveComponent*> getPhysicsComponents(AActor* actor);

    static UObject* LoadObject(const std::string& name);
    static UClass* LoadClass(const std::string& name);

    static void setUnrealClockSpeed(const AActor* context, float clock_speed);
	static float getUnrealClockSpeed(const AActor* context);
    static IImageWrapperModule* getImageWrapperModule();
    static void CompressImageArray(int32 width, int32 height, const TArray<FColor>& src, TArray<uint8>& dest);
    static std::vector<msr::airlib::MeshPositionVertexBuffersResponse> GetStaticMeshComponents();

private:
    template<typename T>
    static void InitializeObjectStencilID(T* mesh, std::map< std::string, int> materialMap, bool ignore_existing = true)
    {
        std::string mesh_name = common_utils::Utils::toLower(GetMeshName(mesh));
        bool painted = false;

        for (std::map<std::string, int>::iterator iter = materialMap.begin(); iter != materialMap.end(); ++iter)
        {
            std::string materialName = iter->first;
            if (common_utils::Utils::contains(mesh_name, "_material_" + materialName)) {
                int value = iter->second;
                if (ignore_existing || mesh->CustomDepthStencilValue == 0) {
                    SetObjectStencilID(mesh, value);
                }
                painted = true;
                break;
            }
        }
        if (!painted) {
            SetObjectStencilID(mesh, 0);
        }
    }

    template<typename T>
    static void SetObjectStencilIDIfMatch(T* mesh, int object_id,
        const std::string& mesh_name, bool is_name_regex, const std::regex& name_regex, int& changes)
    {
        std::string comp_mesh_name = GetMeshName(mesh);
        if (comp_mesh_name == "")
            return;
        bool is_match = (!is_name_regex && (comp_mesh_name == mesh_name))
            || (is_name_regex && std::regex_match(comp_mesh_name, name_regex));
        if (is_match) {
            ++changes;
            SetObjectStencilID(mesh, object_id);
        }
    }

    template<typename T>
    static void SetObjectStencilID(T* mesh, int object_id)
    {
        if (object_id < 0)
        {
            mesh->SetRenderCustomDepth(false);
        }
        else
        {
            mesh->SetCustomDepthStencilValue(object_id);
            mesh->SetRenderCustomDepth(true);
        }
        //mesh->SetVisibility(false);
        //mesh->SetVisibility(true);
    }

    static void SetObjectStencilID(ALandscapeProxy* mesh, int object_id)
    {
        if (object_id < 0)
        {
            mesh->bRenderCustomDepth = false;
        }
        else
        {
            mesh->CustomDepthStencilValue = object_id;
            mesh->bRenderCustomDepth = true;
        }

        // Explicitly set the custom depth state on the components so the
        // render state is marked dirty and the update actually takes effect
        // immediately.
        for (ULandscapeComponent* comp : mesh->LandscapeComponents)
        {
            if (object_id < 0)
            {
                comp->SetRenderCustomDepth(false);
            }
            else
            {
                comp->SetCustomDepthStencilValue(object_id);
                comp->SetRenderCustomDepth(true);
            }
        }
    }


    template <typename T>
    static void SetRenderCustomDepth(T* mesh, bool enable)
    {
        mesh->SetRenderCustomDepth(enable);
    }

    static void SetRenderCustomDepth(ALandscapeProxy* mesh, bool enable)
    {
        mesh->bRenderCustomDepth = enable;

        for (ULandscapeComponent* comp : mesh->LandscapeComponents) {
            comp->SetRenderCustomDepth(enable);
        }
    }

    static bool CompressUsingImageWrapper(const TArray<uint8>& uncompressed, const int32 width, const int32 height, TArray<uint8>& compressed);

private:
    static bool log_messages_hidden_;
    //FViewPort doesn't expose this field so we are doing dirty work around by maintaining count by ourselves
    static uint32_t flush_on_draw_count_;

    static IImageWrapperModule* image_wrapper_module_;
};
