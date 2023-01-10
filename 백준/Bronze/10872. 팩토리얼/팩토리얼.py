def solve(x):
    if x == 0:
        return 1
    return x*solve(x-1)

x = int(input())

print(solve(x))
