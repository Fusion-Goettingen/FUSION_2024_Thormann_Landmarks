import torch
import lightning.pytorch as pl


class HeatmapLandmarkDetector(pl.LightningModule):
    def __init__(self,
                 learning_rate=1e-3,
                 weight_decay=0.01,
                 lr_step_size=None,
                 lr_gamma=None
                 ):
        super().__init__()
        layers = [
            torch.nn.Conv2d(in_channels=4, out_channels=8, kernel_size=(3, 3), padding='same'),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=8, out_channels=32, kernel_size=(3, 3), padding='same'),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=32, out_channels=64, kernel_size=(3, 3), padding='same'),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=64, out_channels=128, kernel_size=(13, 64), padding=(6, 0)),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=128, out_channels=128, kernel_size=(7, 1), padding='same'),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=128, out_channels=64, kernel_size=(5, 1), padding='same'),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=64, out_channels=32, kernel_size=(3, 1), padding='same'),
            torch.nn.ReLU(),
            torch.nn.Conv2d(in_channels=32, out_channels=1, kernel_size=(3, 1), padding='same'),
        ]

        self._model = torch.nn.Sequential(*layers)
        self.learning_rate = learning_rate
        self.weight_decay = weight_decay
        self.lr_step_size = lr_step_size
        self.lr_gamma = lr_gamma

        self.criterion = torch.nn.BCEWithLogitsLoss()

        self.validation_step_outputs = []
        self.training_step_outputs = []

        self.validation_epoch_losses = []
        self.training_epoch_losses = []

    def training_step(self, batch, batch_idx):
        range_doppler_image, label = batch
        gt_range = label.float()

        result_range_map = self.forward(range_doppler_image)
        result_range_map = result_range_map.flatten()

        gt_range_map = torch.zeros(len(result_range_map))
        gt_range_map[torch.floor(gt_range*len(result_range_map)).type(torch.int64)] = 1.0
        gt_range_map = gt_range_map.to("cpu" if result_range_map.get_device() == -1 else result_range_map.get_device())

        loss = self.loss(result_range_map, gt_range_map)
        self.log('train_loss', loss)
        self.training_step_outputs.append(loss)
        return loss

    def loss(self, y_hat, y):
        return self.criterion(y_hat.resize_as(y), y)

    def validation_step(self, batch, batch_idx):
        range_doppler_image, label = batch
        gt_range = label.float()

        result_range_map = self.forward(range_doppler_image)
        result_range_map = result_range_map.flatten()

        gt_range_map = torch.zeros(len(result_range_map))
        gt_range_map[torch.floor(gt_range*len(result_range_map)).type(torch.int64)] = 1.0
        gt_range_map = gt_range_map.to("cpu" if result_range_map.get_device() == -1 else result_range_map.get_device())

        loss = self.loss(result_range_map, gt_range_map)
        self.log('val_loss', loss)
        self.validation_step_outputs.append(loss)
        return loss

    def forward(self, range_doppler_image):
        return self._model(range_doppler_image.float())

    def configure_optimizers(self):
        optimizer = torch.optim.AdamW(self.parameters(),
                                      lr=self.learning_rate,
                                      weight_decay=self.weight_decay)

        if self.lr_step_size is not None and not type(self.lr_step_size) == str:
            scheduler = torch.optim.lr_scheduler.StepLR(optimizer,
                                                        step_size=self.lr_step_size,
                                                        gamma=self.lr_gamma,
                                                        verbose=True)
            return [optimizer], [scheduler]
        else:
            return optimizer

    def on_train_epoch_end(self) -> None:
        avg_loss = torch.stack(self.training_step_outputs).mean().cpu().detach().numpy()
        self.training_epoch_losses.append(avg_loss)
        self.training_step_outputs.clear()

    def on_validation_epoch_end(self):
        """
        On validation epoch end, all outputs from validation epoch steps will be averaged and printed to console if this
        function is registered to be called in that case.
        """
        avg_loss = torch.stack(self.validation_step_outputs).mean().cpu().detach().numpy()
        print("\nValidation epoch end loss: {:.5f}\n".format(avg_loss))
        self.validation_epoch_losses.append(avg_loss)
        self.validation_step_outputs.clear()

    def on_save_checkpoint(self, checkpoint):
        checkpoint['manual_epoch_losses'] = {
            "training": self.training_epoch_losses,
            "validation": self.validation_epoch_losses,
        }

    def on_load_checkpoint(self, checkpoint):
        self.training_epoch_losses = checkpoint['manual_epoch_losses']["training"]
        self.validation_epoch_losses = checkpoint['manual_epoch_losses']["validation"]
