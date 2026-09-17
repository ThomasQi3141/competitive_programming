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
    n = int_input()
    arr = list_input()
    if n % 2 == 1:
        print("NO")
        return
    cnt = Counter(arr)
    if -1 not in cnt:
        cnt[-1] = 0
    if 1 not in cnt:
        cnt[1] = 0
    # swapping (-1, +1) doesn't matter, need to swap 2 adj
    minKey, maxKey = min(cnt, key=lambda x : cnt[x]), max(cnt, key=lambda x : cnt[x])
    if cnt[minKey] == cnt[maxKey]:
        print("YES")
        return
    for i in range(n - 1):
        if arr[i] == arr[i + 1] and arr[i] == maxKey:
            cnt[maxKey] -= 2
            cnt[minKey] += 2
        if cnt[minKey] == cnt[maxKey]:
            print("YES")
            return
    print("NO")
        
if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()