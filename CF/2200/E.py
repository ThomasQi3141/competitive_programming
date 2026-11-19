import sys
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, inf, floor, ceil, isqrt
from itertools import accumulate
# from functools import cache

# sys.setrecursionlimit(10 ** 6)

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

max_n = 1_000_000
spf = [i for i in range(max_n + 1)]
for i in range(2, isqrt(max_n) + 1):
    if spf[i] == i: # skip composites (i.e., still unclaimed)
        for j in range(i * i, max_n + 1, i):
            if spf[j] == j:
                spf[j] = i

def solve():
    # if its not a perfect power of a prime, alice can always get the highest prime from the number (eventually)
    # alice always wins if each composite number is not a perfect power of some prime
    # if the number is a perfect power of some prime, can just reduce it to that number instead
    # -> e.g. 27 = 3, 3, 3
    _ = int_input()
    arr = list_input()
    # check if alice even gets to play
    if all(arr[i] >= arr[i - 1] for i in range(1, len(arr))):
        print("Bob")
        return
    # NOTE: DONT REBUILD SIEVE INSIDE EACH LOOP! VERY SLOW
    # for each number, check if its a perfect power (i.e. only 1 prime factor)
    # if not, return alice
    for i, n in enumerate(arr):
        first_factor = -1
        while n > 1:
            if first_factor == -1:
                first_factor = spf[n]
            elif first_factor != -1 and spf[n] != first_factor:
                print("Alice")
                return
            n //= spf[n]
        # otherwise, len(factors) <= 1
        if first_factor != -1:
            arr[i] = first_factor
    print("Bob" if all(arr[i] >= arr[i - 1] for i in range(1, len(arr))) else "Alice")



if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()