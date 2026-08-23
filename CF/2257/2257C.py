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
    # building a decision tree?
    # place camera at the edge connecting to a subtree -> beaver vists THAT subtree
    # placing a camera at that edge, eliminate the entire subtree? 
    # WORST -> 1 camera per vertex -> m - 1 cameras
    # always m-1!
    # can just place it at m-1 edges where a_i is a child, then just leave one out
    _ = list_input() # actual edges don't actually matter
    m = int_input()
    # if a_i = 1 = root, then can't place it there, no other special cases
    a = set(list_input())
    if 1 in a:
        a.remove(1)
    else:
        a.remove(next(iter(a)))
    # print(a)
    print(" ".join([str(m - 1)] + [str(x) for x in a]))


if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()