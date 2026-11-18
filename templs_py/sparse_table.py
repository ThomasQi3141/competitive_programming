from math import floor, log2

# NOTE: this only works on operations that are idempotent (i.e. overlapping intervals)
# precompute floor(log) for 1..n
# O(n log n) to build the table, O(1) per query
# Doesn't support range queries

# IDEA: st[i][k] = min(A[i..i + 2^k - 1])

# -> TO BE COMPLETED

def build(arr):
    n = len(arr)
    LOG = n.bit_length() # floor(log2(n)) + 1 for n >= 1, and 0 for n = 0
    st = [arr.copy()]
    for k in range(1, LOG):
        pass