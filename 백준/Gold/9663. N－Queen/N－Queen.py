import sys
input = sys.stdin.readline

N = int(input())

rowList = [-1]*N # 인덱스 = column, 값 = row
count = 0

def checkSafe(idx, row):
    for i in range(N):
        if i == idx or rowList[i] == -1:
            continue
        if abs(idx - i) == abs(rowList[i] - row):
            return False
    return True
    

def solve(currentRow):
    if currentRow == N: # N개 다 채움
        global count
        count += 1
        return
    
    for i in range(N):
        if rowList[i] != -1: # 이미 사용중인 column
            continue
        if checkSafe(i, currentRow):
            rowList[i] = currentRow
            solve(currentRow + 1) # 다음 row
            rowList[i] = -1

solve(0)
print(count)
