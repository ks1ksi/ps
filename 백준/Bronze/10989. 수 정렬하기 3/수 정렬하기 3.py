import sys
input = sys.stdin.readline
N = int(input().rstrip())
cSort = [0]*10001

while N > 0:
    num = int(input().rstrip())
    cSort[num] += 1
    N -= 1

for i in range(10001):
    if cSort[i] > 0:
        cnt = cSort[i]
        while cnt > 0:
            print(i)
            cnt -= 1
