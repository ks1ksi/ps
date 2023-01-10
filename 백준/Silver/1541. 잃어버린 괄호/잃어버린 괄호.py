expString = input()
expString += ' '
i = 0
ans = 0
minus = False

expLength = len(expString)
while i < expLength:
    if '0' <= expString[i] <= '9':
        startIndex = i
        while '0' <= expString[i] <= '9':
            i += 1
        endIndex = i
        i -= 1
        currentNum = int(expString[startIndex:endIndex])
        if minus is True:
            ans -= currentNum
        else:
            ans += currentNum
        # print(currentNum)
    elif expString[i] == '-':
        minus = True
    i += 1

print(ans)
