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
    # c = length of previous consecutive seq of 1s
    # v = d * sum(a[..i]) + sum(all r[j] where c = p[j])
    # 1. rewards -> p_j -> r_j
    # say that there's a run of k 1s
    # 1...111 <- length k (assuming k < n)
    # c=1, c=2, ..., c=k
    # TOTAL REWARDS = rewards[1] (r_j with p_j = 1) + 
    # 1. TOTAL_REWARDS += k * d
    # 2. TOTAL_REWARDS += sum(rewards[i] for i in range(1, k + 1)) -> prefix sum probably
    
    # if run of 1s >= n -> break it into ceil(length / n) * q chunks of size n, and remaining chunk of size r
    # -> i.e. CAPS our longest run to n consecutive 1s
    
    # CAN we do better than I(a)?
    # the ONLY way we can do better than I(a) is to maximize the "bonus" rewards r_j
    
    # when size of run > max(p_j) -> no reward! 
    # maximize the runs where length == max(p_j)
    
    # r_3 = r_j where p_j = 3, r_2
    # OPTIMAL STRATEGY: get as MANY runs as we can with length max_run_len = min(max(p_j), n) -> we're CAPPED at run length n
    # 
    
    # 11101110111 -> (r_<=3) * 3 + d * 9
    # 11111111111 -> d * 12 + r_<=3
    # f(a) - f(I(a)) = r_<=3 * 2 - 3d
    
    # both were length k ->
    # f(I(a)) = d * k + sum(r_<=max_run_len) * (k / n) + sum(r<=max_run_len)
    # f(a) = d * (k - (k // max_run_len))
    
    # if n < max(p_j)

    # if sum(r_<=x) / x
    
    
    # NOTE: can always remove last 0, don't need it to separate runs
    
    
    
    # NOTE: we can IGNORE the last d
    
    # -> we can build sucn an array IF sum(r_<=max_run_len) > d
    # i.e., get enough bonus value where it offsets the d
    pass
    
    
    


if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()