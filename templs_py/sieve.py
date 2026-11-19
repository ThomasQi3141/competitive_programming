from math import isqrt

# NOTE: isqrt(n) basically = floor(sqrt(n)) -> max i s.t. i * i <= n

# IDEA: [2, sqrt(n)], i = candidate prime factor
# for each multiple of i, check if anyone has "claimed" it yet, if not, spf is i

max_n = 1_000_000
spf = [i for i in range(max_n + 1)]
for i in range(2, isqrt(max_n) + 1):
    if spf[i] == i: # skip composites (i.e., still unclaimed)
        for j in range(i * i, max_n + 1, i):
            if spf[j] == j:
                spf[j] = i