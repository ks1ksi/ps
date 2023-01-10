import heapq
import sys

input = sys.stdin.readline

INF = 987654321

V = int(input())
E = int(input())
dist = [INF] * (V + 1)

graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

def dijkstra(start):
    dist[start] = 0
    q = []
    heapq.heappush(q, (0, start))
    while q:
        c, t = heapq.heappop(q)
        if c > dist[t]:
            continue
        for i in graph[t]:
            if dist[i[0]] > c + i[1]:
                dist[i[0]] = c + i[1]
                heapq.heappush(q, (c + i[1], i[0]))

v1, v2 = map(int, input().split())

dijkstra(v1)
print(dist[v2])
