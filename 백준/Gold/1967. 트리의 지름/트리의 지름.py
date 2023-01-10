import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
tree = [[] for _ in range(n+1)]
dist = [0] * (n+1)
visited = [False] * (n+1)

for _ in range(n-1):
    a, b, c = map(int, input().split())
    tree[a].append((b, c)) # a to b, c is cost
    tree[b].append((a, c))


def dfs(n, v):
    for i in tree[n]:
        if not visited[i[0]]:
            visited[i[0]] = True
            d = dfs(i[0], v+i[1])
            dist[i[0]] = d
    return v

visited[1] = True
dfs(1, 0)

m = 0
idx = 0
for i in range(1, n+1):
    if dist[i] > m:
        m = dist[i]
        idx = i

visited = [False] * (n+1)
dist = [0] * (n+1)
visited[idx] = True
dfs(idx, 0)

print(max(dist))
