from collections import deque

N = int(input())
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
graph = [input() for _ in range(N)]
visited = [[False] * N for _ in range(N)]


def bfsRGB():
    count = 0
    q = deque()
    for i in range(N):
        for j in range(N):
            if visited[i][j] is False:
                count += 1
                visited[i][j] = True
                q.append((i, j))
                color = graph[i][j]
                while q:
                    row, col = q.popleft()
                    for k in range(4):
                        nextRow = row + dy[k]
                        nextCol = col + dx[k]
                        if nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= N:
                            continue
                        elif graph[nextRow][nextCol] != color:
                            continue
                        elif visited[nextRow][nextCol] is True:
                            continue
                        else:
                            visited[nextRow][nextCol] = True
                            q.append((nextRow, nextCol))
    return count


a = bfsRGB()
visited = [[False] * N for _ in range(N)]
for i in range(N):
    graph[i] = graph[i].replace('R', 'G')
b = bfsRGB()
print(f"{a} {b}")
