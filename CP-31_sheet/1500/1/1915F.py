import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n = int_input()
    # ends = SortedList() # sortedlist of ends
    # intervals = []
    # for _ in range(n):
    #     a, b = list_input()
    #     intervals.append((a, b))
    #     ends.add(b)
    # intervals.sort()
    # res = 0
    # for start, end in intervals:
    #     ends.remove(end)
    #     numLess = ends.bisect_left(end)
    #     res += numLess
    # print(res)

if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()