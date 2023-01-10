import sys
import math
input = sys.stdin.readline

def solve(n):
    v = math.sqrt(n)

    s = math.floor(v)
    e = s + 1
    ans = 2 * s - 1

    if n == s ** 2:
        pass
    elif n - s**2 <= (e**2 - s**2) // 2:
        ans += 1
    else:
        ans += 2

    print(ans)

T = int(input())
for _ in range(T):
    x, y = map(int, input().split())
    dist = y - x
    solve(dist)
