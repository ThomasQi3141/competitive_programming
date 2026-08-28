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
    # 2d matrix
    # A(r, c) == B(r, c) -> 0 flips on r and c OR 1 flip on r + 1 flip on c
    # A(r, c) != B(r, c) -> 1 flip on this row, or this column
    # entry = 1 if need 1 flip, entry = 0 if need 2 or 0 flips
    # entry = A(r, c) ^ B(r, c)
    # by bitfliping an entire row, 
    # 1. ordering of flips doesn't matter
    # 2. after some number of row flips, we want to be left with only columns of 1s or 0s
    # for each element, want it to be the same as element above it -> make columns of 1s or 0s
    # -> each row has to be of form x, or ~x! 
    # -> if its NOT the form of x or ~x -> we will never be able to make it into form x (needed to make columns same)
    # -> some bit is ALWAYS going to be messed up
    n = int_input()
    A = []
    for _ in range(n):
        curRow = string_input()
        # int(curRow, 2) -> read as base 2
        A.append(int(curRow, 2))
        
    string_input() # blank line
    
    for i in range(n):
        curRow = string_input()
        A[i] ^= (int(curRow, 2))
    # print(A)
    # NOTE: can't just ~, gotta mask it
    x = A[0]
    # 110
    # 001 -> 110
    mask = (1 << n) - 1 # -> n digits of 1
    for i in range(1, n):
        # NOTE: python ints are infinite precision, so we ONLY flip the bits we ant
        # otherwise: if x = 101 -> ~x = 111..1010 = -2 in 2s complement
        # but if we do ~x & mask = 111 -> 111..1010 & 111 -> 010 = correct flip
        if A[i] != x and A[i] != ~x & mask:
            print("NO")
            return
    print("YES")

if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()