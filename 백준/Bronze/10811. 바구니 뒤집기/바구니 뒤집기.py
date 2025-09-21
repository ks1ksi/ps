import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = [i for i in range(n + 1)]

for _ in range(m):
    i, j = map(int, input().split())
    mid = (i + j) // 2
    for k in range(i, mid + 1):
        arr[k], arr[i + j - k] = arr[i + j - k], arr[k]

for i in range(1, n + 1):
    print(arr[i], end=" ")
