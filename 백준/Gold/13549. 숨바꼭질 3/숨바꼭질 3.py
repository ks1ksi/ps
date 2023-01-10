import sys
import heapq
input = sys.stdin.readline

N, K = map(int, input().split())
visited = [0] * 100001

def solve(start, end):
    q = []
    heapq.heappush(q, (0, start))
    visited[start] = 1
    while q:
        c, x = heapq.heappop(q)
        if x == end:
            print(c)
            return
        if x * 2 <= 100000 and (visited[x * 2] == 0):
            visited[x * 2] = 1
            heapq.heappush(q, (c, x * 2))
        if x + 1 <= 100000 and (visited[x + 1] == 0):
            visited[x + 1] = 1 
            heapq.heappush(q, (c + 1, x + 1))
        if x - 1 >=0 and (visited[x - 1] == 0):
            visited[x - 1] = 1
            heapq.heappush(q, (c + 1, x - 1))

solve(N, K)

