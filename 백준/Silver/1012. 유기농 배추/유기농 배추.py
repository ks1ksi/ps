import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]


def dfs(graph, visited, row, col):
    if visited[row][col] is True or graph[row][col] == 0:
        return False
    visited[row][col] = True
    for i in range(4):
        ny = row + dy[i]
        nx = col + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            dfs(graph, visited, ny, nx)
    return True


T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    graph = [[0]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    cabbages = []
    cnt = 0
    for _ in range(K):
        X, Y = map(int, input().split())
        graph[Y][X] = 1
        cabbages.append([Y, X])
    for i in cabbages:
        if dfs(graph, visited, i[0], i[1]):
            cnt += 1
    print(cnt)


