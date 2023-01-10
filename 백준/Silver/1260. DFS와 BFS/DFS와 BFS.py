from collections import deque

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end = ' ')
    for i in graph[v]:
        if (visited[i] is False):
            visited[i] = True
            dfs(graph, i, visited)

            
def bfs(graph, v, deq, visited):
    visited[v] = True
    print(v, end = ' ')
    while True:
        for i in graph[v]:
            if visited[i] is False:
                print(i, end = ' ')
                visited[i] = True
                deq.append(i)
        if deq:
            v = deq.popleft()
        else:
            break
            
            
N, M, V = map(int, input().split())
graph = [[]for _ in range(N + 1)]
visited = [True] + [False] * N
deq = deque()

for i in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)
    graph[B].append(A)
for i in graph:
    i.sort()
    
dfs(graph, V, visited)
print()
visited = [True] + [False] * N
bfs(graph, V, deq, visited)
