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
    # returns if this current array works
    def works(nums):
        visited = set()
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                visited.add(nums[i - 1])
                if nums[i] in visited:
                    return False
        return True
    n = int_input()
    arr = list_input()
    # see if it works w/o swaps
    if works(arr):
        print("YES")
        return
    blocks = defaultdict(list)
    start = 0
    for i in range(1, len(arr)):
        if arr[i] != arr[i - 1]:
            blocks[arr[i - 1]].append([start, i - 1])
            start = i
    blocks[arr[-1]].append([start, len(arr) - 1])
    # if any > 3 blocks, doesn't work
    if any(len(y) > 3 for y in blocks.values()):
        print("NO")
        return
    candidate = -1
    # now we try stuff with > 1 blocks by cases
    for x, y in blocks.items():
        if len(y) > 1:
            candidate = x
            break
    intervals = blocks[candidate]
    in_bound = lambda x : 0 <= x < len(arr)
    # candidateLength can only be 2 or 3
    swaps = []
    # for each block, try: start - 1, end + 1 swapped with any other 1-block
    for i in range(len(intervals)):
        # try swapping with all 1-blocks
        for j in range(len(intervals)):
            if i == j: # same block
                continue
            # works for if j is a 1-block or not
            if in_bound(intervals[i][0] - 1):
                swaps.append((intervals[i][0] - 1, intervals[j][0]))
                swaps.append((intervals[i][0] - 1, intervals[j][1]))
            if in_bound(intervals[i][1] + 1):
                swaps.append((intervals[i][1] + 1, intervals[j][0]))
                swaps.append((intervals[i][1] + 1, intervals[j][1]))
    for x, y in swaps:
        arr[x], arr[y] = arr[y], arr[x]
        if works(arr):
            print("YES")
            return
        # swap back
        arr[x], arr[y] = arr[y], arr[x]
    print("NO")
    return


if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()