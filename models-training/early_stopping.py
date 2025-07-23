class EarlyStopping:
    def __init__(self, patience=10, delta=1e-4, verbose=False):
        """
        Args:
            patience (int): How long to wait after the last improvement.
            delta (float): Minimum change in the monitored metric to qualify as improvement.
            verbose (bool): Print early stopping messages.
        """
        self.patience = patience
        self.delta = delta
        self.verbose = verbose
        self.counter = 0
        self.best_score = None
        self.early_stop = False

    def __call__(self, val_loss, model):
        """Monitor validation loss and check for early stopping."""
        score = -val_loss  # We minimize val_loss, so negate it for easy comparison.

        if self.best_score is None or score > self.best_score + self.delta:
            self.best_score = score
            self.counter = 0
        else:
            self.counter += 1
            if self.verbose:
                print(f"EarlyStopping counter: {self.counter}/{self.patience}")
            if self.counter >= self.patience:
                self.early_stop = True
                if self.verbose:
                    print("Early stopping triggered. Final model weights will be saved.")
