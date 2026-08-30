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
    # LHS: < l elem, > r elem on LHS
    # [0, l - 1], [r + 1, curIdx] -> either delete <= i - (r + 1) elements, or delete >= i - (l - 1) elements
    
    # if we delete element -> 1 less elem for everything in RHS AND we remove the requirement intervals for that elem
    
    # LHS: [1, 3], [2, 4], []
    # dp[i] = min deletions for arr[..i] to work? 
    # if we delete this current element
    # -> removing this interval requirement
    # -> everthing LHS -> -= 1 right index
    # -> everything RHS -> -= 1 left index

    # deletions = k
    # if we choose to delete this elem -> everything on RHS is 1 step closer to [l, r] interval

    # IDEA: validify of element DEPENDS on m -> try to FORCE the size to be m for each run -> see if that can work
    
    n = int_input()
    LHS = [(0, 0)] # padding
    RHS = [(0, 0)]
    for _ in range(n):
        l, r, u, v = list_input()
        LHS.append((l, r))
        RHS.append((u, v))
    # print(LHS)
    # print(RHS)
    for numDeletions in range(n + 1):
        works = True
        k = numDeletions
        removals = 0
        for i in range(1, n + 1):
            # delete this or not
            # case 1: don't delete -> perform k deletions on stuff to the right of this
            # -> rightindex = n - k - i + 1 -> will the new index violate??? 
            # -> leftindex stays as i, so if we're not currently violating, it's fine
            # ok, if we don't delete this, will the constraints end up being violated
            # IF leftindex is violating OR rightindex violates in the future after removing k-1 from right side
            # -> MUST delete this interval
            # if RHS condition won't hold if we delete k elements to the right -> doesn't work
            if (LHS[i][0] <= (i - removals) <= LHS[i][1]) or (RHS[i][0] <= (n - i + 1 - k) <= RHS[i][1]) or (n - i + 1 == k):
                # MUST DELETE this -> shifts the left index of stuff on right
                # NOTE: if there are k elements left including this, NEED to delete! 
                k -= 1
                removals += 1
            # gotta start forcing deletions -> if k elements left -> MUST delete them all
            
            # if less than k elements can be deleted on RHS, can't make this work with numDeletions OR more deletions than k
            # i.e. if we can't perform k total deletions -> doesn't work
            if k < 0:
                works = False
                break
        if works:
            print(n - numDeletions)
            return

if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()