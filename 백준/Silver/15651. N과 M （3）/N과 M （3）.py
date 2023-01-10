import sys
input = sys.stdin.readline

N, M = map(int, input().split())

seq = []


def solve(seq, count):
    if count == 0:
        for i in seq:
            print(i, end=' ')
        print()

    else:
        for i in range(N):


            seq.append(i + 1)
            solve(seq, count - 1)

            seq.pop()


solve(seq, M)
