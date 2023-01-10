N = int(input())
point = [list(map(int, input().split())) for _ in range(N)]
point.sort()
for p in point:
    print(p[0], p[1])
