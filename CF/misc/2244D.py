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
    arr = list_input()
    p = list_input() # productivity
    # for each one, you can choose to swap or not swap a segment
    for i in range(m):
        p[i] -= 1 # make it 0-indexed
    p.sort()
    # now p contains like 0 2 4 -> [0, 0] [1, 2] [3, 4]
    # for each of these intervals, we can take the sum, or the flipped sum -> take the max for each = res
    res = 0
    cur_pos = 0
    cur_neg = 0
    for i in range(m):
        interval = []
        if i == 0: # first elem, start from 0
            interval = [0, p[i]]
        else:
            interval = [p[i - 1] + 1, p[i]]
        # print(interval)
        # calculate the sum and flipped
        for j in range(interval[0], interval[1] + 1):
            cur_pos += arr[j]
            cur_neg -= arr[j]
        res += max(cur_pos, cur_neg)
        cur_pos = cur_neg = 0 # reset
    # print(res)
    # if max value of p doesn't cover everything, the rest of the array has to be as is
    if p[-1] < len(arr) - 1:
        res += sum(arr[p[-1] + 1:])
    print(res)

if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()