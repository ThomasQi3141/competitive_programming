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

class UF(dict):
    def __missing__(self, x):
        self[x] = x
        return x

class DSU:
    def __init__(self):
        self.rank = defaultdict(lambda : 1)
        self.parent = UF()
    
    def find(self, x):
        while x != self.parent[x]:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, x, y):
        xPar, yPar = self.find(x), self.find(y)
        if xPar == yPar:
            return False
        if self.rank[xPar] > self.rank[yPar]:
            # make sure rank[xPar] < rank[yPar]
            xPar, yPar = yPar, xPar
        self.parent[xPar] = yPar
        self.rank[yPar] += self.rank[xPar]
        return True


def solve():
    n = int_input()
    s = input()
    uf = DSU()
    # if its alternating, then it always moves right
    # if its all the same -> then infinite back n forth -> alternating = 1 direction
    # if we can explore something, we can always come back
    # | R | L | R | L |
    # union-find -> each node has (x, 0/1 = even/odd)
    # each one has access to moves i-1 and i
    # NOTE: slow, dont need tuple key + don't need 2 loops, each "edge" just contributes to 2 edges
    for i in range(n + 1):
        for parity in range(2):
            if i - 1 >= 0:
                if (s[i - 1] == 'L' and parity % 2 == 0) or (s[i - 1] == 'R' and parity % 2 == 1):
                    uf.union((i, parity), (i - 1, (parity + 1) % 2))
            if i < len(s):
                if (s[i] == 'R' and parity % 2 == 0) or (s[i] == 'L' and parity % 2 == 1):
                    uf.union((i, parity), (i + 1, (parity + 1) % 2))
    # for each component -> take the size but de-dupe it
    components = defaultdict(set)
    for i in range(n + 1):
        for parity in range(2):
            par = uf.find((i, parity))
            components[par].add(i)
    # print(components)
    res = []
    for i in range(n + 1):
        res.append(str(len(components[uf.find((i, 0))])))
    print(" ".join(res))

if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()