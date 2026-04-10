import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf
from functools import cache

# sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


# MLE for this problem?????
# def solve():
#     n = int_input()
#     arr = list_input()
#     @cache
#     def dfs(i):
#         if i > n:
#             return inf
#         if i == n:
#             return 0
#         # can either delete cur or count block
#         return min(dfs(i + arr[i] + 1), dfs(i + 1) + 1)
#     print(dfs(0))

def solve():
    n = int_input()
    arr = list_input()
    dp = [inf] * n
    dp[-1] = 1
    for i in range(n - 2, -1, -1):
        # consider deleting current block
        dp[i] = dp[i + 1] + 1
        if i + arr[i] == n - 1:
            dp[i] = 0
        elif i + arr[i] < n - 1:
            dp[i] = min(dp[i], dp[i + arr[i] + 1])
    print(dp[0])


if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()