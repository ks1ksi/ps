import sys
input = sys.stdin.readline

N, M = map(int, input().split())
numList = list(map(int, input().split()))
numList.sort()

visited = [False]*N
seq = []
seqset = set()


def solve(visited, seq, count):
    if count == 0:
        tSeq = tuple(seq)
        if tSeq not in seqset:
            for i in seq:
                print(i, end=' ')
            print()
            seqset.add(tSeq)

    else:
        for i in range(N):
            '''
            if visited[i] is True:
                continue
            '''
            if seq:
                if numList[i] < seq[-1]:
                    continue

            visited[i] = True
            seq.append(numList[i])
            solve(visited, seq, count - 1)
            visited[i] = False
            seq.pop()


solve(visited, seq, M)
