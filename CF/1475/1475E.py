import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf, floor, ceil
from itertools import accumulate
# from functools import cache

# sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))

def exp(base, pow, mod):
    res = 1
    while pow > 0:
        if pow % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        pow //= 2
    return res

def solve():
    # sort this in decreasing order -> then do (followers, count)
    # while curCount + count < k -> safely pick everyone in this group
    # for the last group, #slots left CHOOSE #(count with x followers)
    # (count) Choose (k - curCount)
    MOD = 10 ** 9 + 7
    n, k = list_input()
    a = list_input()
    arr = []
    cnt = Counter(a)
    for followers, count in cnt.items():
        arr.append((followers, count))
    arr.sort(reverse=True)
    cur = 0
    pos = 0
    while pos < len(arr) and cur + arr[pos][1] < k:
        cur += arr[pos][1]
        pos += 1
    if pos == len(arr) or arr[pos][1] == k - cur:
        print(1)
        return
    # now, cur < k, have k - cur slots left
    # basically compute (arr[pos][1]) Choose (k - cur)
    fact = [1] * (arr[pos][1] + 1)
    for i in range(1, len(fact)):
        fact[i] = (fact[i - 1] * i) % MOD
    factInv = [1] * (arr[pos][1] + 1)
    # a^p-2 is modular inverse of a
    factInv[-1] = exp(fact[-1], MOD - 2, MOD)
    # 1/(i)! = i+1/(i+1)!
    for i in range(len(factInv) - 2, -1, -1):
        factInv[i] = ((i + 1) * factInv[i + 1]) % MOD
    if k - cur > arr[pos][1]:
        k -= arr[pos][1]
    # print(all((fact[i] * factInv[i]) % MOD == 1 for i in range(len(factInv))))
    # print(f"k-cur: {k - cur}")
    # print(f"arr[pos][1]: {arr[pos][1]}")
    print((fact[arr[pos][1]] * factInv[k - cur] * factInv[arr[pos][1] - (k - cur)]) % MOD)

if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()