import mlflow
import matplotlib.pyplot as plt
import os
import torch

class MLflowLogger:
    def __init__(self, experiment_name="Experiment"):
        mlflow.set_tracking_uri("file:./mlruns")
        mlflow.set_experiment(experiment_name)  # Set the MLflow experiment
        self.run = None

    def __enter__(self):
        """Start an MLflow run when entering the context."""
        self.run = mlflow.start_run(log_system_metrics=True)
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        """End the MLflow run when exiting the context."""
        mlflow.end_run()

    def log_params(self, params):
        """Log hyperparameters to MLflow."""
        for key, value in params.items():
            mlflow.log_param(key, value)

    def log_metrics(self, metrics):
        """Log metrics to MLflow."""
        if metrics is not None:
            for key, value in metrics.items():
                mlflow.log_metric(key, value)
    
    def log_metrics_per_epoch(self, metrics):
        """Log metrics per epochs to MLflow"""
        if metrics is not None:
            # Dynamically take the number of the epochs
            epochs = next(iter(metrics.values()))
            
            for epoch in range(epochs):
                # Log metrics with 'step' for epochs
                for metric_name, metric_values in metrics.items():
                    if isinstance(metric_values, (list, tuple)):
                        mlflow.log_metric(metric_name, metric_values[epoch], step=epoch + 1)

    def plot_and_log_artifacts(self, metrics_per_epoch, save_dir="plots_for_metrics_per_epoch"):
        """
        Plot metrics and save them to MLflow as artifacts.
        Plots train loss and validation loss on the same plot if available.

        Args:
            metrics_per_epoch (dict): Dictionary containing metrics per epoch.
            save_dir (str): Directory to save plots before logging to MLflow.
        """
        if metrics_per_epoch is not None:
            # Create the directory to save plots
            if not os.path.exists(save_dir):
                os.makedirs(save_dir)

            # Extract epochs
            epochs = range(1, metrics_per_epoch["epochs"] + 1)

            # Plot train_loss and val_loss together if both are present
            if "train_loss" in metrics_per_epoch and "val_loss" in metrics_per_epoch:
                # Convert list of tensors to NumPy arrays
                train_loss = [v.cpu().item() if isinstance(v, torch.Tensor) else float(v) for v in metrics_per_epoch["train_loss"]]
                val_loss = [v.cpu().item() if isinstance(v, torch.Tensor) else float(v) for v in metrics_per_epoch["val_loss"]]
                
                plt.figure()
                plt.plot(epochs, train_loss, marker='o', label="Train Loss")
                plt.plot(epochs, val_loss, marker='o', label="Validation Loss")
                plt.title("Training and Validation Loss over Epochs")
                plt.xlabel("Epochs")
                plt.ylabel("Loss")
                plt.legend()
                plt.grid(True)

                # Save the combined loss plot
                loss_plot_path = os.path.join(save_dir, "loss_curve.png")
                plt.savefig(loss_plot_path)
                plt.close()

                # Log the combined loss plot to MLflow
                mlflow.log_artifact(loss_plot_path, artifact_path="metrics_plots")

            # Iterate over other metrics (excluding "epochs", "train_loss", "val_loss")
            for metric_name, values in metrics_per_epoch.items():
                if metric_name in ["epochs", "train_loss", "val_loss"]:
                    continue
                
                # Simplify metric name for display
                display_name = metric_name.replace("_per_epoch", "")
                
                # Convert list of tensors to scalars if necessary
                values = [v.cpu().item() if isinstance(v, torch.Tensor) else float(v) for v in values]

                # Create the plot
                plt.figure()
                plt.plot(epochs, values, marker='o', label=display_name)
                plt.title(f"{display_name} over Epochs")
                plt.xlabel("Epochs")
                plt.ylabel(display_name)
                plt.legend()
                plt.grid(True)

                # Save the plot locally
                plot_path = os.path.join(save_dir, f"{display_name}.png")
                plt.savefig(plot_path)
                plt.close()

                # Log the plot as an artifact in MLflow
                mlflow.log_artifact(plot_path, artifact_path="metrics_plots")
    
    def log_model(self, model, artifact_path="model"):
        """Save the model in a MLFlow Experiment."""
        mlflow.log_artifact(model, artifact_path=artifact_path)
             
    def end_run(self):
        """End the current MLflow run."""
        if self.run:
            mlflow.end_run()