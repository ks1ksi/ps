from collections import deque

N, K = map(int, input().split())
pos = [0] * 100001
deq = deque()

def solve(start, end):
    deq.append(start)
    while deq:
        current = deq.popleft()
        if current == end:
            return pos[current]
        plusOne = current + 1
        minusOne = current - 1
        multiplyTwo = current * 2
        if plusOne <= 100000 and pos[plusOne] == 0:
            deq.append(plusOne)
            pos[plusOne] = pos[current] + 1
        if minusOne >= 0 and pos[minusOne] == 0:
            deq.append(minusOne)
            pos[minusOne] = pos[current] + 1
        if 0 < multiplyTwo <= 100000 and pos[multiplyTwo] == 0:
            deq.append(multiplyTwo)
            pos[multiplyTwo] = pos[current] + 1
        

print(solve(N, K))
        