from types import GeneratorType

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if type(to) is GeneratorType:
                stack.append(to)
                to = next(to)
            else:
                stack.pop()
                if not stack:
                    break
                to = stack[-1].send(to)
        return to
    return wrappedfunc


# # --- Backtracking example: all subsets summing to target ---
# def solve():
#     n, target = map_input()
#     a = list_input()
#     path = []
#     res = []

#     @bootstrap
#     def bt(i, s):
#         if s == target:
#             res.append(path[:])      # copy the current state
#         if i == n or s > target:
#             yield None               # "return"
#         for j in range(i, n):
#             path.append(a[j])        # choose
#             yield bt(j + 1, s + a[j])  # recurse
#             path.pop()               # undo
#         yield None                   # end of function

#     bt(0, 0)
#     print(len(res))


# # --- Returning a value example: subtree sizes ---
# @bootstrap
# def dfs(u, p):
#     size = 1
#     for v in adj[u]:
#         if v != p:
#             size += yield dfs(v, u)  # get the child's return value
#     sz[u] = size
#     yield size                       # "return size"