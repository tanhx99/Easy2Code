import math
import torch
import torch.nn as nn
import torch.nn.functional as F

class MultiHeadAttention(nn.Module):
    def __init__(self, d_model, num_heads, dropout=0.1):
        super().__init__()
        assert d_model % num_heads == 0
        self.d_model = d_model
        self.num_heads = num_heads
        self.d_k = d_model // num_heads
        
        self.W_q = nn.Linear(d_model, d_model)
        self.W_k = nn.Linear(d_model, d_model)
        self.W_v = nn.Linear(d_model, d_model)
        self.dropout = nn.Dropout(dropout)
        self.W_o = nn.Linear(d_model, d_model)

    def split_heads(self, x, batch_size):
        x = x.view(batch_size, -1, self.num_heads, self.d_k)
        return x.transpose(1, 2)

    def forward(self, x, key_padding_mask=None, attn_mask=None):
        batch_size = x.size(0)
        Q = self.W_q(x)
        K = self.W_k(x)
        V = self.W_v(x)

        Q = self.split_heads(Q, batch_size)
        K = self.split_heads(K, batch_size)
        V = self.split_heads(V, batch_size)

        scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(self.d_k)
        if attn_mask is not None:
            attn_mask = attn_mask.unsqueeze(0).unsqueeze(1)
            scores = scores.masked_fill(attn_mask == 0, -1e9)
        if key_padding_mask is not None:
            key_padding_mask = key_padding_mask.unsqueeze(1).unsqueeze(2)
            scores = scores.masked_fill(key_padding_mask == 0, -1e9)
        attention_weights = F.softmax(scores, dim=-1)
        if self.dropout is not None:
            attention_weights = self.dropout(attention_weights)
        output = torch.matmul(attention_weights, V)
        
        output = output.transpose(1, 2).contiguous().view(batch_size, -1, self.d_model)
        output = self.W_o(output)
        return output


batch_size = 16
seq_length = 20
d_model = 768
num_heads = 12

input = torch.rand(batch_size, seq_length, d_model)

# 模拟随机的句子长度
random_lens = torch.randint(low=1, high=seq_length, size=(batch_size,))
key_padding_mask = torch.zeros(batch_size, seq_length)
for i in range(batch_size):
    key_padding_mask[i, :random_lens[i]] = 1

# masked multi-head attention
attn_mask = torch.tril(torch.ones(seq_length, seq_length))

attention_layer = MultiHeadAttention(d_model, num_heads)
output = attention_layer(input, key_padding_mask, attn_mask)
print("Output shape:", output.shape)  # [16, 20, 768]
