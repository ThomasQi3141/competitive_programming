import sys

input = sys.stdin.readline

# string to seconds
def str_to_int(string):
    arr = [int(x) for x in string.split(":")]
    return arr[0] * 60 * 60 + arr[1] * 60 + arr[2]


def int_to_str(num):
    # hours, minutes, seconds
    arr = [num // (60 * 60), num % (60 * 60) // 60, num % 60]
    res = ["0" + str(x) if x < 10 else str(x) for x in arr]
    return ":".join(res)

def calc_segments(num):
    segments = [6,2,5,5,4,5,6,3,7,6]
    return sum(segments[x % 10] + segments[x // 10] for x in (num // (60 * 60), num % (60 * 60) // 60, num % 60))

def solve():
    time = str_to_int(input().rstrip("\n"))
    cur_segments = calc_segments(time)
    for i in range(time - 1, -1, -1):
        if calc_segments(i) == cur_segments:
            print(int_to_str(i))
            return
    for i in range(str_to_int("23:59:59"), 0, -1):
        if calc_segments(i) == cur_segments:
            print(int_to_str(i))
            return
    # nothing found "BEFORE" this
    

if __name__ == "__main__":
    solve()