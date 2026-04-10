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
    n, k = list_input()
    arr = list_input()
    arr.sort()
    def works(target):
        cur = 1 # cur number of pos we have
        prev = arr[0]
        for i in range(1, len(arr)):
            if arr[i] - prev >= target:
                prev = arr[i]
                cur += 1
        return cur >= k
    l, r = 0, arr[-1]
    res = r
    while l <= r:
        mid = (l + r) // 2
        if works(mid):
            res = mid
            l = mid + 1
        else:
            r = mid - 1
    print(res)


if __name__ == "__main__":
    t = 1
    # t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()