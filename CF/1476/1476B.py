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
    n, k = list_input()
    p = list_input()
    # for each pi, increase some values s.t.
    # -> just wanna put everything into p0 if possible, p0 doesn't affect itself
    # pi / (sumof(p[i-1]) + p0) <= k/100
    # 100 * pi <= k * (sum + p0) -> p0 = max(p0, 100 * pi / k - sum)
    prefix = list(accumulate(p[1:]))
    prefix.insert(0, 0) # prefix is 0-padded
    # print(p)
    # print(prefix)
    newP0 = p[0]
    for i in range(1, n):
        # print((p[i] / (prefix[i - 1] + p[0])) <= k / 100)
        newP0 = max(newP0, ceil((100 * p[i] / k) - prefix[i - 1]))
    print(newP0 - p[0])



if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()