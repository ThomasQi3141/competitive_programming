import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf

# sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n, m = list_input()
    a = list_input()
    b = list_input()
    if n < m * 2:
        print("NO")
        return
    a.sort()
    b.sort()
    # NOTE: we need to pick m disjoint pairs in a s.t. x_j <= b_j <= y_j -> can just throw the rest away
    # n >= 2m -> m lower values, m higher values
    # for each x in b -> want to use the BIGGEST value thats <= x
    # see if we can map the m lowest values -> all b[i] and m highest values to all b[i]
    # a[0...m-1] -> b[0...m-1]
    # a[n-m...n-1] -> b[0...m-1]
    for i, x in enumerate(b):
        if b[i] < a[i] or b[i] > a[n - (m - i)]:
            print("NO")
            return
    print("YES")



if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()