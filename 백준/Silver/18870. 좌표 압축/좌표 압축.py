import sys
input = sys.stdin.readline

N = int(input())
points = list(map(int, input().split()))

sortedPoints = list(sorted(set(points)))
compressedPoints = {sortedPoints[i]:i for i in range(len(sortedPoints))}

for i in points:
    print(compressedPoints[i], end = ' ')
