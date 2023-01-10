import heapq
import sys

input = sys.stdin.readline

INF = 987654321

V, E = map(int, input().split())
init = 1

graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

def dijkstra(start):
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

res1 = 0

dist = [INF] * (V + 1)
dist[init] = 0
dijkstra(init)
res1 += dist[v1]

dist = [INF] * (V + 1)
dist[v1] = 0
dijkstra(v1)
res1 += dist[v2]

dist = [INF] * (V + 1)
dist[v2] = 0
dijkstra(v2)
res1 += dist[V]

res2 = 0

dist = [INF] * (V + 1)
dist[init] = 0
dijkstra(init)
res2 += dist[v2]

dist = [INF] * (V + 1)
dist[v2] = 0
dijkstra(v2)
res2 += dist[v1]

dist = [INF] * (V + 1)
dist[v1] = 0
dijkstra(v1)
res2 += dist[V]

res = min(res1, res2)

if res >= INF:
    print(-1)
else:
    print(res)
