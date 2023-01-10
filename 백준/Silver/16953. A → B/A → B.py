A, B = map(int, input().split())


def solve(a, b):
    cnt = 1
    while True:
        if b == a:
            return cnt
        if b % 10 == 1 and b != 1:
            b //= 10
            cnt += 1
        elif b % 2 == 0:
            b //= 2
            cnt += 1
        else:
            return -1


print(solve(A, B))
