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
    a = list_input()
    b = list_input()
    # if a[i] == 0 -> get for free with an odd flip
    # either we can't flip and return -1, or this doesn't contribute to anything
    
    # if a[i] == b[i] -> dont need to flip
    
    # count #pairs where a[i] == 1, b[i] = 0
    
    # if pairs % 2 == 0 -> need 2 flips, else 1
    
    cnt10 = 0
    cnt01 = 0
    cnt11 = 0
    cnt00 = 0
    for i in range(n):
        if a[i] == 1 and b[i] == 0:
            cnt10 += 1
        elif a[i] == 0 and b[i] == 1:
            cnt01 += 1
        elif a[i] == 1 and b[i] == 1:
            cnt11 += 1
        else:
            cnt00 += 1
    # we can solve 01 2 ways:
    # if we have 01 with 10s, then we can always get 01 for free
    # if we have 11 and a 00
    if cnt10 == 0:
        # we don't have to print -1, can just flip and flip back WITH a 1
        if cnt01 > 0:
            if cnt11 > 0 and cnt00 > 0:
                print(2)
                return
            # otherwise, no way of solving
            print(-1)
            return
        print(0) # everything is good, cnt10 == cnt01 == 0
        return
    if cnt10 % 2 == 0:
        print(2)
    else:
        print(1)



if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()