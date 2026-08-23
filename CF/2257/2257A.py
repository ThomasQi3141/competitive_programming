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


def solve():
    n, m = list_input()
    s = set()
    for _ in range(n):
        s.add(input()[0].upper())
    # print(s)
    # NOTE: input() captures the \n
    arr = [input()[:-1] for _ in range(m)]
    # print(arr)
    for i in range(m):
        if any(c.upper() not in s for c in arr[i]):
            # print(arr[i])
            print("NO")
            return
    print("YES")



if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()