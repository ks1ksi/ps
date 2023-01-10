import sys
import heapq

input = sys.stdin.readline
N = int(input())

maxHeap = []

for i in range(N):
    num = int(input())
    if num != 0:
        heapq.heappush(maxHeap, num)
    else:
        if not maxHeap:
            print(0)
        else:
            print(heapq.heappop(maxHeap))

