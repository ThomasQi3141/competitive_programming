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
    n, k = list_input()
    # if n % 2 == 0 -> num1 = num0
    # if n % 2 == 1 -> num0 = num1 + 1
    # sum of x - 1 for x in consecutive_runs must add up to k
    # 5 2
    # 01110
    # 11001
    # to create a new pair, can append same char, or append 2x diff char
    # 0011001
    # 0011 -> 2
    # 00011 -> 3
    # 000111 -> 4
    # 00001111 -> 6
    # max number of pairs = n - 2
    if k > n - 2:
        print(-1)
        return
    # 4 -> 2, 1, 0
    # 0011
    # 0110
    # 0101
    # 5 -> 3 2 1 0
    # 11000 -> 01100 -> 10100 -> 01010
    # -> for each string, try to "break" the block up
    # start with 000111
    numPairs = n - 2
    # how many times do we have to interleave
    diff = numPairs - k # number of pairs to get rid of
    if k == numPairs:
        if n % 2 == 0:
            print('0' * (n // 2) + '1' * (n // 2))
        else:
            print('0' * (n // 2) + '1' * (n // 2 + 1))
        return
    num1 = num0 = n // 2
    if n % 2 == 1:
        num0 += 1
    if n % 2 == 1:
        n -= 1
        k -= 1
    res = []
    # now, assume n % 2 == 0
    # 000111 -> 01
    res.append('01' * (diff // 2) + '0' * (diff % 2))
    num0 -= (diff // 2 + diff % 2)
    num1 -= diff // 2
    if diff % 2 == 0:
        # end with 1
        res.append('0' * num1 + '1' * num0)
    else:
        res.append('1' * num1 + '0' * num0)
    final = ''.join(res)
    if n % 2 == 1:
        if k == -1:
            if final[-1] == '1':
                print(final + '0')
            else:
                print(final + '1')
        else:
            if final[-1] == '0':
                print(final + '0')
            else:
                print(final + '1')
    else:
        print(final)
    # 6 3 -> 111000 -> 011100


if __name__ == "__main__":
    t = 1
    t = int_input() # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()