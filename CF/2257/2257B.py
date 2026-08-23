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
    # determine how many rocks it takes for them to stand on 0
    # basically the array is shifted by 1? each mountain contributes arr[i] - arr[i - 1]
    n, m = list_input()
    a = list_input()
    b = list_input()
    # NOTE: jumping mountains = 1 turn too
    aSum = sum(a[i] - a[i + 1] + 1 for i in range(n - 1))
    bSum = sum(b[i] - b[i + 1] + 1 for i in range(m - 1))
    aSum += a[-1]
    bSum += b[-1]
    # print(b)
    # print(aSum)
    # print(bSum)
    if aSum >= bSum:
        print(1)
    else:
        print(2)



if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()