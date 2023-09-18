import torch
import torch.nn as nn

class FeedForward(nn.Module):
    def __init__(self, d_model, d_ff=2048, dropout=0.1):
        super().__init__()
        self.linear1 = nn.Linear(d_model, d_ff)
        self.linear2 = nn.Linear(d_ff, d_model)
        self.dropout = nn.Dropout(dropout)
        self.relu = nn.ReLU()
        
    def forward(self, x):
        x = self.linear1(x)
        x = self.relu(x)
        x = self.dropout(x)
        x = self.linear2(x)
        return x


d_model = 768
feedforward_layer = FeedForward(d_model)
input_tensor = torch.rand(16, 20, d_model)
output_tensor = feedforward_layer(input_tensor)
print(output_tensor.shape)  # [16, 20, 768]
