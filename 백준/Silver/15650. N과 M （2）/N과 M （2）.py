import sys
input = sys.stdin.readline

N, M = map(int, input().split())
visited = [False]*N
seq = []


def solve(visited, seq, count):
    if count == 0:
        for i in seq:
            print(i, end=' ')
        print()

    else:
        for i in range(N):
            if visited[i] is True:
                continue
            if seq:
                if i + 1 < seq[-1]:
                    continue

            visited[i] = True
            seq.append(i + 1)
            solve(visited, seq, count - 1)
            visited[i] = False
            seq.pop()


solve(visited, seq, M)
