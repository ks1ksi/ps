N = int(input())
for _ in range(N):
    oxString = input()
    strLength = len(oxString)
    strIndex = 0
    score = 0
    continueO = 1
    while strIndex < strLength:
        if oxString[strIndex] == 'O':
            score += continueO
            continueO += 1
        else:
            continueO = 1
        strIndex += 1
    print(score)
