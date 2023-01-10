import sys
from collections import deque
input = sys.stdin.readline

M, N = map(int, input().split())
tomatoBox = [list(map(int, input().split())) for _ in range(N)]
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]


def bfs(graph):
    row, col = 0, 0
    dq = deque()
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                dq.append([i, j])

    while dq:
        row, col = dq.popleft()
        for i in range(4):
            if 0 <= row + dy[i] < N and 0 <= col + dx[i] < M:
                if graph[row + dy[i]][col + dx[i]] == 0:
                    dq.append([row + dy[i], col + dx[i]])
                    graph[row + dy[i]][col + dx[i]] = graph[row][col] + 1

    for i in graph:
        if 0 in i:
            return -1
    return graph[row][col] - 1


print(bfs(tomatoBox))
