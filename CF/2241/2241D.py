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
    # disregard a and b, just get the diff
    # operation is: diff[l..r] += [1,-1,1,-1,...]
    # if diff[i] == 3 with i % 2 == 0:
    # means that we HAVE to choose diff[l..r] 3 times where i - l % 2 == 0
    n = int_input()
    a = list_input()
    b = list_input()
    diff = [a[i] - b[i] for i in range(n)]
    # print(diff)
    # if diff is like [1, 1] -> impossible since [2, 0] -> impossible now
    # if diff is like [-1, -1] -> choose l=r=0, l=r=1
    # we can basically get rid of all negatives "for free"
    # idea: get rid of positives first
    # -> can basically "shift" positives down by choosing [i-1, i] diff[i] times
    # -> so diff[i - 1] += diff[i], diff[i] = 0
    # [-3, 2, 3, 5] -> [-3, 2, 8, 0] -> [-3, 10, 0, 0] -> [7, 0, 0, 0] -> IMPOSSIBLE! 
    # shift the positive values down -> then if a[0] > 0, impossible
    # can we shift negatives down -> NO!
    # [3, 3, -2] -> only way to "shift" -2 down, [1, -1, 1] doesn't do anything since the first 1 counteracts
    for i in range(len(diff) - 1, 0, -1):
        if diff[i] > 0:
            # shift down
            diff[i - 1] += diff[i]
            diff[i] = 0
    print("YES" if diff[0] <= 0 else "NO")


if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()