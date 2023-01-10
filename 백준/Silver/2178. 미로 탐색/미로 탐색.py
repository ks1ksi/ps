from collections import deque

N, M = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(N)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def bfs():
    q = deque()
    q.append((0, 0))
    while q:
        row, col = q.popleft()
        for i in range(4):
            nextRow = row + dy[i]
            nextCol = col + dx[i]
            if nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M:
                continue
            elif graph[nextRow][nextCol] != 1:
                continue
            else:
                graph[nextRow][nextCol] = graph[row][col] + 1
                q.append((nextRow, nextCol))


bfs()
print(graph[N - 1][M - 1])
