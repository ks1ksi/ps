import sys
input = sys.stdin.readline

N, M = map(int, input().split())

arr = [[0] + list(map(int, input().split())) for _ in range(N)]
arr.insert(0, [0] * (N + 1))

for row in range(N + 1):
    for col in range(1, N + 1):
        arr[row][col] += arr[row][col - 1]

for col in range(N + 1):
    for row in range(1, N + 1):
        arr[row][col] += arr[row - 1][col]

for _ in range(M):
    r1, c1, r2, c2 = map(int, input().split())
    ans = arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1]
    print(ans)
