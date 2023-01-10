import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
pos = [(0, 0)] * 100001

def solve(start, end):
    q = deque()
    q.append(start)
    while q:
        x = q.popleft()
        if x == K:
            print(pos[x][1])
            break
        if x - 1 >= 0 and pos[x - 1] == (0, 0):
            pos[x - 1] = (x, pos[x][1] + 1)
            q.append(x - 1)
        if x + 1 <= 100000 and pos[x + 1] == (0, 0):
            pos[x + 1] = (x, pos[x][1] + 1)
            q.append(x + 1)
        if x * 2 <= 100000 and pos[x * 2] == (0, 0):
            pos[x * 2] = (x, pos[x][1] + 1)
            q.append(x * 2)

    ans = [x]
    while x != start:
        ans.append(pos[x][0])
        x = pos[x][0]
    
    while ans:
        print(ans.pop(), end=' ')

solve(N, K)

