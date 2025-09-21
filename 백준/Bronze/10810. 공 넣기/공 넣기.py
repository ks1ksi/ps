import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = [0] * n

for _ in range(m):
    i, j, k = map(int, input().split())
    for d in range(i - 1, j):
        arr[d] = k

for x in arr:
    print(x, end=" ")
