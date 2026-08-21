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
    n = int_input()
    c = list_input()
    a = list_input()
    b = list_input()
    # if a[i] == b[i] -> it closes the loop & starts a new one
    # otherwise, it always continues
    prev_length = 0
    # if you take abs(a[i] - b[i]) -> closing the loop
    # for each one, i can either:
    # 1. close it here,
    # 2. close it until the next one
    # if a[i] == b[i] -> close it here
    
    # previous one is either
    # last_loop_size + (bi - c[i - 1]) + (ai - 1) + 2 - (b - a)
    # OR 
    # (bi - ai) + 2 + c[i]
    
    prev_size = -inf
    res = 0
    for i in range(1, n):
        ai, bi = min(a[i], b[i]), max(a[i], b[i])
        if ai == bi:
            # forced close, no option
            cur_size = (bi - ai) + 2 + c[i] - 1
        else:
            # current length
            cur_size = max(prev_size - (bi - ai) + 2 + c[i] - 1, (bi - ai) + 2 + c[i] - 1)
        # print(ai, bi)
        # print(cur_size)
        res = max(res, cur_size)
        prev_size = cur_size
    print(res)

        
            
if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()