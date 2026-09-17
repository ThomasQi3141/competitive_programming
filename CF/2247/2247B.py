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
    n, k, m = list_input()
    # a bunch of m+1? 
    # [k elements that sum up to m]
    # [m//k + 1 (m % k times), then m//k]
    
    # every subarray of length < k -> is cm + r for some c > 0, 1 <= r < m
    # (r1 + r2 + r3 + ..) cannot be % m = 0
    
    # 6 4 3 -> n k m
    # if m < k
    # [1 1 1 1 1 0] or something -> NEVER works because i can take the first m elements
    if m < k:
        print("NO")
        return
    print("YES")
    if m == k:
        arr = ["1"] * n
        print(" ".join(arr))
        return
    # m > k -> 
    # m+1 k times? 
    # have the first k-1 elements sum to m-1 -> last element m+1
    arr = []
    arr.append(str(2 * m - k + 1))
    
    # have first element be m + m - k + 1 -> rest are just 1
    
    # if k > 1:
    #     arr.extend([str((m - 1) // (k - 1) + 1)] * ((m - 1) % (k - 1)))
    #     arr.extend([str((m - 1) // (k - 1))] * (k - 1 - (m - 1) % (k - 1)))
    # arr.append(str(m + 1))
    arr.extend([str(1)] * (n - len(arr)))
    print(" ".join(arr))



if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()