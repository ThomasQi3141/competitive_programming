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
    # obs: 1 <= elements <= 2 -> anything > 2 elements HAS a palindrome and can be reduced to 10/01/0/1
    # case 1: 11 or 00
    # -> can always reduce to 1 and 0
    # ANY palindrome can be reduced to its outermost element! 
    # find longest palindrome each time and reduce to outermost -> continue doing so until no palindrome of length >= 2
    n = int_input()
    a = list(string_input())
    # GREEDY DOESN'T WORK -> 101100 -> 1100 -> 2
    # optimal is: 101100 -> 10100 -> 0100 -> 000 -> 00 -> 0
    # stack = []
    # # if its the case of like 10 -> next element gotta be 1 or 0
    # # -> if next element 1 -> 101 -> reduces to 1
    # for i in range(len(a)):
    #     # cases: 00/11, 101/010
    #     if stack and a[i] == stack[-1]:
    #         # case: 00/11, just continue
    #         continue
    #     if len(stack) == 2:
    #         # 101/010 case, reduces to 1/0
    #         stack.pop()
    #     else:
    #         stack.append(a[i])
    # print(stack)
    # print(len(stack))
    
    # 1 <= length <= 2 -> figure out if 1 element is possible
    # 1 element possible ONLY if we can reduce to 000...000 or 111...111
    # if 01111...1110 -> can remove ALL
    # if 1111110 -> can only remove till 10
    # IDEA: dont let first AND last element be different 
    # if we can make the first == last element by deleting -> EVERYTHING else can be collapsed, and we'll have length == 1
    if a[0] == a[-1]:
        print("1")
        return
    else:
        # otherwise, a[0] != a[-1], see if there's any element in between them that can delete a[0] or a[-1]
        # front_run = first idx s.t. a[idx] != a[0]
        # back_run = last idx s.t. a[idx] != a[-1]
        # both will be in bound since the 0..0 or 1..1 case is filtered out by first part
        front_run, back_run = 0, len(a) - 1
        while a[front_run] == a[0]:
            front_run += 1
        while a[back_run] == a[-1]:
            back_run -= 1
        # remove the runs
        a = [a[0]] + a[front_run:back_run + 1] + [a[-1]]
        pos = 1
        while pos < len(a):
            if a[pos] == a[0]:
                # means that first elem is removable -> return 1
                print("1")
                return
            pos += 1
        pos = len(a) - 2
        while pos >= 0:
            if a[pos] == a[-1]:
                # means last elem is removable -> Return 1
                print("1")
                return
            pos -= 1
    print("2")

    
    
if __name__ == "__main__":
    t = 1
    t = int_input()  # REMEMBER TO COMMENT OUT IF NOT NEEDED
    for _ in range(t):
        solve()