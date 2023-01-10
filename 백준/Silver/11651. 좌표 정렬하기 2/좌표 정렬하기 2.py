N = int(input())
point = [list(map(int, input().split())) for _ in range(N)]
sortedPoint = sorted(point, key=lambda x: (x[1], x[0]))
for p in sortedPoint:
    print(p[0], p[1])
