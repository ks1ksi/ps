import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [True] + [False]*N
connectedComponentCount = 0


def dfs(vertex):
    if visited[vertex]:
        return False
    visited[vertex] = True
    for i in graph[vertex]:
        if not visited[i]:
            dfs(i)
    return True


for i in range(M):
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)
for i in graph:
    i.sort()

for i in range(1, N + 1):
    if dfs(i):
        connectedComponentCount += 1

print(connectedComponentCount)
