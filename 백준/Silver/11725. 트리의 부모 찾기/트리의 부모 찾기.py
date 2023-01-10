import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())

visited = [False] * (N + 1)
graph = [[] for _ in range(N + 1)]
parents = [1] * (N + 1)

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


def dfs(start):
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            parents[i] = start
            dfs(i)


dfs(1)
for n in range(2, N + 1):
    print(parents[n])
