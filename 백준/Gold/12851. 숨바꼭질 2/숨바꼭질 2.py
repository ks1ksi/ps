import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
pos = [0] * 100001

def solve(start, end):
    q = deque()
    q.append(start)
    while q:
        x = q.popleft()
        if x == K:
            print(pos[x])
            break
        if x - 1 >= 0 and (pos[x - 1] == 0 or pos[x - 1] > pos[x]):
            pos[x - 1] = pos[x] + 1
            q.append(x - 1)
        if x + 1 <= 100000 and (pos[x + 1] == 0 or pos[x + 1] > pos[x]):
            pos[x + 1] = pos[x] + 1
            q.append(x + 1)
        if x * 2 <= 100000 and (pos[x * 2] == 0 or pos[x * 2] > pos[x]):
            pos[x * 2] = pos[x] + 1
            q.append(x * 2)
    ans = 1
    while q:
        x = q.popleft()
        if x == K:
            ans += 1
    print(ans)

solve(N, K)
