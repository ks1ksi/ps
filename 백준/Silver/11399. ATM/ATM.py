N = int(input())
time = list(map(int, input().split()))
time.sort()
sumList = [time[0]]
for i in range(1, len(time)):
    sumList.append(sumList[i-1] + time[i])
print(sum(sumList))
