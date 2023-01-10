N = int(input())
crainList = list(map(int, input().split()))
crainSize = len(crainList)
M = int(input())
boxList = list(map(int, input().split()))
boxList.sort(reverse=True)
crainList.sort(reverse=True)

cnt = 0

if boxList[0] > crainList[0]:
    print(-1)

else:
    while boxList:
        crainIdx = 0
        i = 0
        while i < len(boxList):
            if boxList[i] > crainList[crainIdx]:
                i += 1
                continue
            else:
                boxList.pop(i)
                i -= 1
                crainIdx += 1
                if crainIdx == crainSize:
                    break
            i += 1
        cnt += 1

    print(cnt)
