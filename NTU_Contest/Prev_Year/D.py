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
    n = int_input()
    a = list_input()
    b = list_input()
    if sum(a) != sum(b):
        print(-1)
        return
    a.sort()
    b.sort()
    res = sum(abs(a[i] - b[i]) for i in range(n))
    print(res // 2)

if __name__ == "__main__":
    t = 1
    # t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()