import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf, floor, ceil
from itertools import accumulate
# from functools import cache

# sys.setrecursionlimit(10 ** 6)

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
    """
    4 0 4
    #3 1 4 2# -> #2 3 1 4# -> # 4 2 3 1# -> # 1 4 2 3#
    3 1 2
    3#2#1 -> #2#3 1
    5 1 3
    1#3 5#2 4 -> 1 2#3 5#4
    2 0 1
    #1#2
    """
    # 3 diff sections
    # middle section can be rotated however you want -> choose smallest lexographical rotation (min element first)
    # 1. reorder middle section
    # 2. slide outer sections left/right
    n, x, y = list_input()
    arr = list_input()
    middle = arr[x : y] # y already 1-indexed
    rest = arr[:x] + arr[y:]
    # 1. reorder middle s.t. its minimal
    min_middle = min(middle)
    idx = -1 
    for i in range(len(middle)):
        if middle[i] == min_middle:
            idx = i
            break
    # reorder middle
    middle = middle[idx:] + middle[:idx]
    # middle is now minimal
    # left and right section has to stay in same relative order, but can slide around
    # keep sliding right until everything LHS < middle?
    # start from rightmost idx, -- until everything to the left of that index is < min_middle
    # i.e. max(res[..idx]) < min_middle -> compute prefix
    max_left = rest.copy()
    for i in range(1, len(max_left)):
        max_left[i] = max(rest[i], max_left[i - 1])
    # print(rest, middle)
    res = middle.copy()
    for i in range(len(max_left) - 1, -1, -1):
        if max_left[i] < min_middle:
            res = rest[:i+1] + middle.copy() + rest[i+1:]
            break
    # special case, where everything in rest is > min_middle
    if max_left and max_left[0] > min_middle:
        res = middle.copy() + rest.copy()
    print(' '.join(str(x) for x in res))


if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()