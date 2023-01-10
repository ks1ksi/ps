import collections
N = int(input())
dq = collections.deque([i for i in range(1, N + 1)])

while len(dq) > 1:
    dq.popleft()
    tmp = dq.popleft()
    dq.append(tmp)

print(dq[0])
