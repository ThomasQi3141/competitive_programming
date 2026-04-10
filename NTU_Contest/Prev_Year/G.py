import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n = int_input()
    cnt = {}
    a = list_input()
    for i in range(1, n + 1):
        cnt[i] = 0
    for x in a:
        cnt[x] += 1
    result = Counter()
    for val in cnt.values():
        result[val] += 1
    res = ""
    for i in range(n):
        res += f"{result[i]} "
    print(res)


if __name__ == "__main__":
    t = 1
    # t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()