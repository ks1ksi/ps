def solve(N):
    if N == 0:
        return 1
    ret = 0
    for i in range(1, 4):
        if N - i >= 0:
            ret += solve(N - i)
    return ret


T = int(input())
while T > 0:
    N = int(input())
    print(solve(N))
    T -= 1
