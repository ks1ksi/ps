from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
N, M = map(int, input().split())

graph = [[[] for _ in range(N)] for _ in range(2)]
for i in range(N):
    str = input()
    for c in str:
        for z in range(2):
            graph[z][i].append(int(c))

def bfs(graph):
    res = 987654321
    q = deque()
    q.append((0, 0, 0))
    graph[0][0][0] = 1
    while q:
        z, y, x = q.popleft()
        if y == N - 1 and x == M - 1:
            res = min(res, graph[z][y][x])
        # 벽을 부수고 온 경우
        if z == 1:
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                # 맵 밖으로 벗어났을 때
                if ny < 0 or nx < 0 or ny >= N or nx >= M:
                    continue
                # 벽 만났을 때 (원본 그래프로 체크)
                elif graph[0][ny][nx] == 1:
                    continue
                # 길 만났을 때
                elif graph[1][ny][nx] == 0:
                    graph[1][ny][nx] = graph[1][y][x] + 1
                    q.append((1, ny, nx))
                # 누가 지나온 길 만났을 때
                else:
                    # 내가 방금 밟은거 아니면
                    if graph[1][ny][nx] != graph[1][y][x] + 1:
                        graph[1][ny][nx] = graph[1][y][x] + 1


        else:
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                # 맵 밖으로 벗어났을 때
                if ny < 0 or nx < 0 or ny >= N or nx >= M:
                    continue
                # 벽 만났을 때 (원본 그래프로 체크)
                elif graph[0][ny][nx] == 1:
                    # 부순 적 없는 벽이면
                    if graph[1][ny][nx] == 1:
                        graph[1][ny][nx] = graph[0][y][x] + 1
                        q.append((1, ny, nx))
                # 길 만났을 때
                elif graph[0][ny][nx] == 0:
                    graph[0][ny][nx] = graph[0][y][x] + 1
                    q.append((0, ny, nx))
                # 지나온 길 만났을 때
                else:
                    continue
    return res


ans = bfs(graph)
if ans == 987654321:
    print(-1)
else:
    print(ans)
