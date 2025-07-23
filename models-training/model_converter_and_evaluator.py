# import torch
# import onnx
# from onnx import helper, TensorProto
# import time
# import tensorrt as trt
# from object_detection_evaluator import ObjectDetectionEvaluator
# from pascal_voc_dataset import PascalVOCDataset
# from torch.utils.data import DataLoader
# from torchvision import transforms as T
# from torchvision.models.detection import ssd300_vgg16, fasterrcnn_mobilenet_v3_large_fpn, _utils
# from torchvision.models.detection.faster_rcnn import FastRCNNPredictor
# from torchvision.models.detection.ssd import SSDClassificationHead
# from effdet import DetBenchPredict, DetBenchTrain, create_model
# import warnings
# import albumentations as A
# import cv2
# from albumentations.pytorch import ToTensorV2
# warnings.filterwarnings("ignore", category=UserWarning)

# class ModelConverterAndEvaluator:
#     def __init__(self, model, test_loader, device):
#         self.model = model
#         self.test_loader = test_loader
#         self.evaluator = ObjectDetectionEvaluator()
#         self.device = device

#     def convert_to_onnx(self, onnx_path, input_size=(1, 3, 640, 640)):
#         """Convert PyTorch model to ONNX."""
#         dummy_input = torch.randn(*input_size).to(self.device)
#         self.model.eval()
#         torch.onnx.export(
#             self.model,
#             dummy_input,
#             onnx_path,
#             export_params=True,
#             opset_version=18,
#             do_constant_folding=True,
#             input_names=["images"],
#             output_names=["predictions"]
#         )
#         print(f"Model converted to ONNX and saved at {onnx_path}")
        
#         #self.fix_onnx_precision(onnx_path)

#     def fix_onnx_precision(self, onnx_path):
#         # Load the ONNX model
#         model = onnx.load(onnx_path)

#         # Fix all outputs to INT32
#         for output in model.graph.output:
#             if output.type.tensor_type.elem_type == TensorProto.INT64:
#                 print(f"Converting output tensor '{output.name}' from INT64 to INT32")
#                 output.type.tensor_type.elem_type = TensorProto.INT32

#         # Fix intermediate initializers and tensors
#         for initializer in model.graph.initializer:
#             if initializer.data_type == TensorProto.INT64:
#                 print(f"Converting initializer '{initializer.name}' from INT64 to INT32")
#                 initializer.CopyFrom(
#                     helper.make_tensor(
#                         name=initializer.name,
#                         data_type=TensorProto.INT32,
#                         dims=initializer.dims,
#                         vals=initializer.int64_data  # Ensure this is valid for your model
#                     )
#                 )

#         # Save the modified model
#         onnx.save(model, "model_fixed.onnx")
#         print("Converted all Int64 tensors to Int32 and saved as 'model1.onnx'")
        
#     def convert_to_tensorrt(self, onnx_path, trt_path, precision='fp16'):
#         """Convert ONNX model to TensorRT with specified precision."""
#         with trt.Builder(trt.Logger(trt.Logger.WARNING)) as builder, \
#          builder.create_network(1 << (int)(trt.NetworkDefinitionCreationFlag.EXPLICIT_BATCH)) as network, \
#          trt.OnnxParser(network, trt.Logger(trt.Logger.WARNING)) as parser:

#             with open(onnx_path, 'rb') as f:
#                 if not parser.parse(f.read()):
#                     for error in range(parser.num_errors):
#                         print(parser.get_error(error))
#                     raise RuntimeError("Failed to parse ONNX model")
            
#             config = builder.create_builder_config()
#             config.set_memory_pool_limit(trt.MemoryPoolType.WORKSPACE, 3 * (1 << 30))
            
#             # Set precision
#             if precision == 'fp16':
#                 config.set_flag(trt.BuilderFlag.FP16)
#             elif precision == 'int8':
#                 config.set_flag(trt.BuilderFlag.INT8)
#             elif precision == 'fp8':
#                 config.set_flag(trt.BuilderFlag.FP8)
#             elif precision == 'int4':
#                 config.set_flag(trt.BuilderFlag.INT8)
#                 config.set_flag(trt.BuilderFlag.RESTRICT_TO_COMPATIBLE_PRECISION)

#             profile = builder.create_optimization_profile()

#             # Add optimization profile for input
#             input_name = network.get_input(0).name
#             profile.set_shape(input_name, min=(1, 3, 640, 640), opt=(1, 3, 640, 640), max=(1, 3, 640, 640))

#             # Add optimization profile for predictions
#             output_name = network.get_output(0).name  # Adjust based on output order
#             profile.set_shape(output_name, min=(1, 4), opt=(80, 4), max=(640, 4))  # Example shapes
#             config.add_optimization_profile(profile)
            
#             # Build serialized engine
#             serialized_engine = builder.build_serialized_network(network, config)
#             if serialized_engine is None:
#                 raise RuntimeError("Failed to build serialized TensorRT engine")

#             # Save serialized engine to disk
#             with open(trt_path, 'wb') as f:
#                 f.write(serialized_engine)
#             print(f"TensorRT engine saved at {trt_path} with precision {precision}")

#     def evaluate_model(self, trt_path, class_mapping, input_size=(3, 640, 640)):
#         """Evaluate TensorRT model for FPS and metrics."""
#         runtime = trt.Runtime(trt.Logger(trt.Logger.WARNING))
#         with open(trt_path, 'rb') as f:
#             engine = runtime.deserialize_cuda_engine(f.read())

#         context = engine.create_execution_context()

#         # Determine input and output tensor names
#         input_name = None
#         output_name = None
#         for idx in range(engine.num_io_tensors):
#             tensor_name = engine.get_tensor_name(idx)
#             tensor_mode = engine.get_tensor_mode(tensor_name)
#             if tensor_mode == trt.TensorIOMode.INPUT:
#                 input_name = tensor_name
#             elif tensor_mode == trt.TensorIOMode.OUTPUT:
#                 output_name = tensor_name

#         if input_name is None or output_name is None:
#             raise RuntimeError("Could not determine input/output tensors.")

#         # Set the input shape dynamically
#         context.set_input_shape(input_name, (1, *input_size))

#         # Prepare buffers
#         input_shape = engine.get_tensor_shape(input_name)
#         output_shape = engine.get_tensor_shape(output_name)
#         input_size = torch.prod(torch.tensor(input_shape))
#         output_size = torch.prod(torch.tensor(output_shape))

#         # Allocate GPU memory
#         device_input = torch.zeros(input_size, dtype=torch.float16).to(self.device)
#         device_output = torch.zeros(output_size, dtype=torch.float16).to(self.device)

#         num_images = 0
#         total_inference_time = 0.0

#         # Bind input and output tensors
#         context.set_tensor_address(input_name, device_input.data_ptr())
#         context.set_tensor_address(output_name, device_output.data_ptr())

#         # Create CUDA stream
#         stream = torch.cuda.Stream()

#         # Begin evaluation
#         for images, targets in self.test_loader:
#             num_images += len(images)
#             images = [img.to(self.device, dtype=torch.float16) for img in images]

#             # Flatten and copy input data
#             device_input.copy_(torch.cat(images).view(-1))

#             # Measure inference time
#             start_time = time.time()
#             with torch.cuda.stream(stream):
#                 context.execute_async_v3(stream.cuda_stream)
#             stream.synchronize()  # Wait for inference to complete
#             end_time = time.time()

#             total_inference_time += (end_time - start_time)

#             # Retrieve outputs
#             outputs = device_output.cpu().numpy()
#             print(outputs)  # Postprocess and evaluate metrics here if needed

#         # Calculate FPS
#         fps = num_images / total_inference_time if total_inference_time > 0 else 0
#         print(f"FPS: {fps}")
#         return fps

import torch
import time
import torch_tensorrt as trtorch
from object_detection_evaluator import ObjectDetectionEvaluator
from pascal_voc_dataset import PascalVOCDataset
from torch.utils.data import DataLoader
from torchvision import transforms as T
from torchvision.models.detection import ssd300_vgg16
from torchvision.models.detection.ssd import SSDClassificationHead
from torchvision.models.detection import _utils
import albumentations as A
import cv2
from albumentations.pytorch import ToTensorV2

torch.autograd.set_detect_anomaly(True)


class ModelConverterAndEvaluator:
    def __init__(self, model, test_loader, device):
        self.model = model
        self.test_loader = test_loader
        self.evaluator = ObjectDetectionEvaluator()
        self.device = device

    def convert_to_torch_tensorrt(self, model, precision='fp32'):
        """Convert PyTorch model to TensorRT using Torch-TensorRT."""    
        
        # Set precision
        enabled_precisions = {torch.float32}
        if precision == 'fp16':
            enabled_precisions = {torch.float16}
        scripted_model = torch.jit.script(model)
        # Compile the Torch-TensorRT model
        trt_model = trtorch.compile(
            model,
            inputs=[
                trtorch.Input([1,3,640,640], dtype=torch.float32)
            ],
            ir="torch_compile",
            enabled_precisions=enabled_precisions,
            truncate_long_and_double=True
        )

        print(f"Model successfully compiled with Torch-TensorRT using precision {precision}")
        return trt_model

    def evaluate_torch_tensorrt_model(self, trt_model, model):
        """Evaluate Torch-TensorRT model for FPS and metrics."""
        num_images = 0
        total_inference_time = 0.0

        # Set the model to evaluation mode
        trt_model.eval()

        with torch.no_grad():
            # Evaluate on the test dataset
            for images, targets in self.test_loader:
                num_images += len(images)
                
                # Move images to the appropriate device
                images = [img.to(self.device) for img in images]

                # Measure inference time
                start_time = time.time()
                outputs = trt_model(images)
                end_time = time.time()

                total_inference_time += (end_time - start_time)

                # Postprocess outputs (if needed)
                # for output in outputs:
                #     print(f"Output: {output}")
        # Calculate FPS
        
        fps = num_images / total_inference_time if total_inference_time > 0 else 0
        print(f"Converted Model -> Processed {num_images} images in {total_inference_time:.2f} seconds. FPS: {fps:.2f}")
        num_images = 0
        with torch.no_grad():
            # Evaluate on the test dataset
            for images, targets in self.test_loader:
                num_images += len(images)

                # Move images to the appropriate device
                images = [img.to(self.device) for img in images]

                # Measure inference time
                start_time = time.time()
                outputs = model(images)
                end_time = time.time()

                total_inference_time += (end_time - start_time)

                # Postprocess outputs (if needed)
                # for output in outputs:
                #     print(f"Output: {output}")

        # Calculate FPS
        fps = num_images / total_inference_time if total_inference_time > 0 else 0
        print(f"Original Model -> Processed {num_images} images in {total_inference_time:.2f} seconds. FPS: {fps:.2f}")
        return fps

if __name__ == "__main__":
    # Create datasets
    test_root = "dataset_pascal/test"
    model_path = "ssd_model.pt"

    # Create transforms
    def get_transforms():
        return A.Compose(
        [
            A.LongestMaxSize(max_size=640),
            A.PadIfNeeded(min_height=640, min_width=640, border_mode=cv2.BORDER_CONSTANT, value=(0, 0, 0)),
            A.Normalize(normalization="min_max_per_channel"),
            ToTensorV2()
        ],
        A.BboxParams(format="pascal_voc", label_fields=["labels"]))
        
    # Create dataset and data loader
    test_dataset = PascalVOCDataset(root_dir=test_root, transforms=get_transforms())
    test_loader = DataLoader(
        test_dataset, batch_size=1, shuffle=False, collate_fn=lambda x: tuple(zip(*x)), num_workers=1
    )

    # Class mapping
    class_mapping = {1: "fire", 2: "smoke"}

    # Load and configure the model
    model = ssd300_vgg16(weights=None)
    in_channels = _utils.retrieve_out_channels(model.backbone, (640, 640))
    num_anchors = model.anchor_generator.num_anchors_per_location()
    model.head.classification_head = SSDClassificationHead(
        in_channels=in_channels, num_anchors=num_anchors, num_classes=3
    )
    model.transform.min_size = (640,)
    model.transform.max_size = 640
    model.score_thresh = 0.3
    model.nms_thresh = 0.5

    # Load weights
    state_dict = torch.load(model_path, map_location="cuda")
    model.load_state_dict(state_dict)

    # Move model to device
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    model = model.to(device).eval()

    # Create the converter
    converter = ModelConverterAndEvaluator(model, test_loader, device)
    
    # Convert the PyTorch model to Torch-TensorRT
    trt_model = converter.convert_to_torch_tensorrt(model, precision='fp32')
    

    # Evaluate the Torch-TensorRT model
    #fps = converter.evaluate_torch_tensorrt_model(trt_model, model)
    import tensorrt as trt
    import numpy as np
    import pycuda.driver as cuda
    import pycuda.autoinit  # Initializes CUDA driver

    # Load the TensorRT engine
    TRT_LOGGER = trt.Logger(trt.Logger.WARNING)
    with open("model_fp32.trt", "rb") as f, trt.Runtime(TRT_LOGGER) as runtime:
        engine = runtime.deserialize_cuda_engine(f.read())

    # Create execution context
    context = engine.create_execution_context()

    # Identify input/output bindings
    input_binding_idx = engine.get_binding_index("input")  # Replace "input" with actual name
    output_binding_idx = engine.get_binding_index("output")  # Replace "output" with actual name

    # Check if input shape is dynamic
    input_shape = engine.get_binding_shape(input_binding_idx)
    if -1 in input_shape:
        dummy_input = np.random.rand(1, 3, 640, 640).astype(np.float32)  # Replace with actual expected input size
        context.set_binding_shape(input_binding_idx, dummy_input.shape)
    else:
        dummy_input = np.random.rand(*input_shape).astype(np.float32)

    # Update output shape based on input shape
    output_shape = context.get_binding_shape(output_binding_idx)

    # Allocate device memory
    d_input = cuda.mem_alloc(dummy_input.nbytes)
    d_output = cuda.mem_alloc(np.prod(output_shape) * np.dtype(np.float32).itemsize)

    # Transfer input to GPU
    cuda.memcpy_htod(d_input, dummy_input)

    # Execute inference
    bindings = [int(d_input), int(d_output)]
    context.execute_v2(bindings)

    # Retrieve output
    output = np.empty(output_shape, dtype=np.float32)
    cuda.memcpy_dtoh(output, d_output)

    print("Inference Output:", output)