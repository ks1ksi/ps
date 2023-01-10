import sys
from collections import deque
input = sys.stdin.readline

M, N, H = map(int, input().split())
tomatoBox = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]

dy = [1, -1, 0, 0, 0, 0]
dx = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]


def bfs(graph):
    height, row, col = 0, 0, 0
    dq = deque()
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if graph[i][j][k] == 1:
                    dq.append([i, j, k])

    while dq:
        height, row, col = dq.popleft()
        for i in range(6):
            if 0 <= height + dz[i] < H and 0 <= row + dy[i] < N and 0 <= col + dx[i] < M:
                if graph[height + dz[i]][row + dy[i]][col + dx[i]] == 0:
                    dq.append([height + dz[i], row + dy[i], col + dx[i]])
                    graph[height + dz[i]][row + dy[i]][col + dx[i]] = graph[height][row][col] + 1

    for i in graph:
        for j in i:
            if 0 in j:
                return -1
    return graph[height][row][col] - 1


print(bfs(tomatoBox))

