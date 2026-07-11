import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n, m = list_input()
    adj = defaultdict(list) # start -> [dist, dest]
    for _ in range(m):
        start, dest, dist = list_input()
        adj[start].append((dist, dest))
    minH = []
    minH.append((0, 1))
    dist = [inf] * (n + 1)
    while minH:
        curDist, node = heappop(minH)
        if curDist >= dist[node]:
            continue
        dist[node] = curDist
        for nbDist, nb in adj[node]:
            if curDist + nbDist < dist[nb]:
                heappush(minH, (curDist + nbDist, nb))
    # w python
    
    print(" ".join(map(str, dist[1:])))
            


if __name__ == "__main__":
    t = 1
    # t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()