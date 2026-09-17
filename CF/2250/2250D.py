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
    # GIVING UP ON THIS FOR NOW
    MOD = 998_244_353
    n = int_input()
    a = list_input()
    # if we want v_i = a_i
    # a_i can occur in LHS, or RHS -> [1, i] = LHS, [i+1, n] = RHS
    # if a_i >= i -> its on LHS, otherwise, its on RHS! ONLY 1 way to put it
    # if on LHS, p[1..i] <= a_i, RHS -> [i+1...n] <= a_i -> NOTE: one idx in the range has to be a_i
    # -> for each element, it has to be <= some value (min(i+1...n))
    # left_min = [2, 2, 3, 4, 5] -> p_1 <= 2, etc. -> how many permutations are there s.t. 

    # interval -> where its element -> [l, r] = element must be in range [l, r]
    left_min = [inf] * (n + 1)
    right_min = [inf] * (n + 1)
    for i in range(1, n):
        ai = a[i - 1]
        if ai >= i:
        else:
    print(element_ranges)
    


if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()