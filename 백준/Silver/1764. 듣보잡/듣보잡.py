import sys

input = sys.stdin.readline
N, M = map(int, input().split())

dSet = {input().rstrip() for _ in range(N)}
bSet = {input().rstrip() for _ in range(M)}
dbList = list(dSet & bSet)
dbList.sort()

print(len(dbList))
for i in dbList:
    print(i)
