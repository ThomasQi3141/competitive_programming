import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf, floor, ceil
from itertools import accumulate

# sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n, q = list_input()
    s = input()
    # define di=1 if BAD pair (i.e. s[i] == s[i+1])
    # NOTE: flipping [a, b] -> we're only flipping d_a-1 and d_b, only 2 things can be changed
    d = [0] * (n - 1)
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            d[i] = 1
    d.insert(0, 0)
    prefix = list(accumulate(d)) # d[i] = total sum of pairs in s[...i]
    # print(d)
    # print(prefix)
    res = []
    for _ in range(q):
        l, r, k = list_input()
        l -= 1
        r -= 1
        # prefix is padded
        cnt = prefix[r] - prefix[l] # number of pairs in [l, r]
        # for each segment, can choose the subsegment to reverse as the outermost bad pairs
        # and then it'll "bubble"
        # so each time, it can eliminate AT MOST 2 bad pairs (if there are 2)
        # if theres 1 -> just swap it
        if ceil(cnt / 2) <= k:
            res.append("YES")
        else:
            res.append("NO")
    print("\n".join(res))

if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()