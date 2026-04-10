import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    t, a, b = list_input()
    minOps = [inf] * (t + 1)
    minOps[0] = 0
    for i in range(t + 1):
        if i - a >= 0 and minOps[i - a] != inf:
            minOps[i] = min(minOps[i], minOps[i - a])
        if i - b >= 0 and minOps[i - b] != inf:
            minOps[i] = min(minOps[i], minOps[i - b])
        if minOps[i] == 0:
            minOps[i // 2] = min(minOps[i // 2], 1)
    for i in range(t + 1):
        if i - a >= 0 and minOps[i - a] != inf:
            minOps[i] = min(minOps[i], minOps[i - a])
        if i - b >= 0 and minOps[i - b] != inf:
            minOps[i] = min(minOps[i], minOps[i - b])
    for i in range(t, -1, -1):
        if minOps[i] != inf:
            print(i)
            return
    print(-1)


if __name__ == "__main__":
    t = 1
    # t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()