import sys

input = sys.stdin.readline

n, m = map(int, input().split())

dic = dict()

for _ in range(n):
    s = input().strip()
    if len(s) < m:
        continue

    if s in dic:
        dic[s] += 1
    else:
        dic[s] = 1

arr = []

for k, v in dic.items():
    arr.append((-v, -len(k), k))

arr.sort()

for x in arr:
    print(x[2])
