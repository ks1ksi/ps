import sys
input = sys.stdin.readline
INF = 987654321
N = int(input())
M = int(input())

dist = [[INF] * (N + 1) for _ in range(N + 1)]

for idx in range(N + 1):
    dist[idx][idx] = 0

for _ in range(M):
    a, b, c = map(int, input().split())
    dist[a][b] = min(dist[a][b], c)

for i in range(1, N + 1):
    for j in range(1, N + 1):
        for k in range(1, N + 1):
            dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k])

for r in range(1, N + 1):
    for c in range(1, N + 1):
        if dist[r][c] == INF:
            print(0, end=' ')
        else:
            print(dist[r][c], end=' ')
    print()
