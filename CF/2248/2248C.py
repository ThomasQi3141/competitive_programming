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


def string_input():
    return input().strip()


def strings_input():
    return input().split()


def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n = int_input()
    arr = list_input()
    numToIdx = {} # num -> first occurence index
    for i, x in enumerate(arr):
        if x not in numToIdx:
            numToIdx[x] = i
    # dp[i] = max score we can get using arr[..i]
    dp = [0] * len(arr)
    dp[0] = 1 # first elem always consumed as single
    for i in range(1, len(arr)):
        # if first occ, no choice but to consume, then 1 + dp[i - 1]
        # if 2nd occ, consume/not consume -> max(dp[idx - 1] + (i - idx + 1) ^ 2, 1 + dp[i - 1])
        if i == numToIdx[arr[i]]:
            # first occ
            dp[i] = 1 + dp[i - 1]
        else:
            firstIdx = numToIdx[arr[i]]
            prev = dp[firstIdx - 1] if firstIdx > 0 else 0
            dp[i] = max(prev + (i - firstIdx + 1) ** 2, 1 + dp[i - 1])
    # print(dp)
    print(dp[-1])

if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()