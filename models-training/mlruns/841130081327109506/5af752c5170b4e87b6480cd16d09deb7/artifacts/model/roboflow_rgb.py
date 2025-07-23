from roboflow import Roboflow

rf = Roboflow(api_key="zAeCsK6HcdoZLxRTyNa3")
workspace = rf.workspace("object-detection-istuk")

workspace.deploy_model(
  model_type="yolov8",
  model_path=".",
  project_ids=["unrela-engine-detections"],
  model_name="my_rgb_model"
)
