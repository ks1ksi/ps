N = int(input())
M = int(input())

if M != 0:
    brokenButtons = set(map(int, input().split()))
else:
    brokenButtons = set()


def selectChannel(channel):
    dif = 987654321
    sel = 987654321
    for i in range(1000000):
        s = True
        for c in brokenButtons:
            if str(c) in str(i):
                s = False
                break
        if not s:
            continue

        # 갈 수 있는 채널
        if abs(channel - i) < dif:
            dif = abs(channel - i)
            sel = i

    return sel


selected = selectChannel(N)
bt = len(str(selected))
print(min(abs(N - 100), abs(selected - N) + bt))
