import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf

input = sys.stdin.readline


def int_input():
    return int(input())

def map_input():
    return map(int, input().split())


def list_input():
    return list(map(int, input().split()))


def solve():
    n, m, k = list_input()
    adj = defaultdict(list)
    for _ in range(m):
        u, v = list_input()
        adj[u].append(v)
        adj[v].append(u)
        
    maxStamina = defaultdict(lambda : -inf)

    maxH = []
    # want to process the largest health nodes!
    for _ in range(k):
        p, h = list_input()
        maxH.append((-h, p))
        
    heapify(maxH)
    while maxH:
        neg_stamina, node = heappop(maxH)
        stamina = -neg_stamina
        
        if stamina <= maxStamina[node]:
            continue
        maxStamina[node] = stamina

        for nb in adj[node]:
            # only push to nb if it improves it
            if stamina - 1 > maxStamina[nb]:
                heappush(maxH, (-1 * (stamina - 1), nb))

    res = []
    for i in range(1, n + 1):
        if maxStamina[i] >= 0:
            res.append(i)
    res.sort()
    print(len(res))
    print(*res)
    


if __name__ == "__main__":
    t = 1
    # t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()