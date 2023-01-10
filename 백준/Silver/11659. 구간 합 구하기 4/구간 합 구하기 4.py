import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nList = [0] + list(map(int, input().split()))

sumList = [0]
for i in range(1, N + 1):
    sumList.append(sumList[i - 1] + nList[i])

for _ in range(M):
    start, end = map(int, input().split())
    print(sumList[end] - sumList[start - 1])
