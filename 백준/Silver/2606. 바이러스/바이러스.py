from collections import deque

v = int(input())
e = int(input())
graph = [[] for _ in range(v+1)]
visited = [False] * (v+1)
deq = deque()

for _ in range(e):
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)


def bfs(start, visited):
    visited[start] = True
    deq.append(start)
    cnt = 0
    while deq:
        v = deq.popleft()
        for i in graph[v]:
            if not visited[i]:
                visited[i] = True
                deq.append(i)
                cnt += 1
    return cnt


print(bfs(1, visited))
