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
    # if some subseq share a common mode? -> can delete

    # c = 0
    # we can ALWAYS remove (0, 0) or (1, 1) pairs
    # a_i, b_i = (0, 0) -> increase 0_cnt on both by 1
    # a_i, b_i = (1, 1) -> decrease 0_cnt on both by 1
    # a_i, b_i = (0, 1) -> 0_cnt_a += 1, 0_cnt_b -= 1
    # a_i, b_i = (1, 0) -> 0_cnt_a -= 1, 0_cnt_b += 1
    
    # if a_i != c -> -1, if a_i = c -> 1
    # c is MODE <-> cnt >= 0
    # we want to pick s.t. cnt >= 0 for BOTH a and b
    
    # 1. group together (0, 1) and (1, 0) pairs -> those will have no affect on cnt
    # 2. we'll have a bunch of (0, 1) or (1, 0) leftover
    # -> each (0, 0) or (1, 1) can take care of a (0, 1), or (1, 0) pair
    # 11 -> cnt = 2
    # 10 -> cnt = 0 -> ALWAYS WORKS
    
    # prefix sum -> count (0, 0), (0, 1)
    # diff1, diff2 = min(01cnt, 10cnt), max(01cnt, 10cnt)
    # diff2 -= diff1
    # if diff2 <= 00cnt + 11cnt -> return True
    # else return False
    n, q = list_input()
    s = string_input()
    t = string_input()
    prefix = [Counter([s[0] + t[0]])]
    for i in range(1, n):
        prefix.append(prefix[i - 1].copy())
        prefix[i][s[i] + t[i]] += 1
    # print(prefix)
    
    res = []
    for _ in range(q):
        l, r = list_input()
        l -= 1
        r -= 1
        # NOTE: cnt is an ALIAS for prefix[r], so it MODIFIES THE ORIGINAL!!!!!
        # NOTE: added .copy() to make sure we're not modifying the original!!!
        cnt = prefix[r].copy()
        if l > 0:
            cnt -= prefix[l - 1] # modifies prefix[r] if no .copy() keyword!!!!!!
        diff = max(cnt["01"], cnt["10"]) - min(cnt["01"], cnt["10"])
        if diff <= cnt["00"] + cnt["11"]:
            res.append("YES")
        else:
            res.append("NO")
    print("\n".join(res))

# 010
# 101

if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()