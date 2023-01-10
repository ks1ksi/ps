import sys
input = sys.stdin.readline

N = int(input())
st = list(map(int, input().split()))

targets = []
ans = [-1] * N

st.reverse()
idx = 0
targets.append((idx, st.pop()))

while st:
    t = st.pop()
    idx += 1

    while targets and targets[-1][1] < t:
        a, b = targets.pop()
        ans[a] = t
    
    targets.append((idx, t))

for i in ans:
    print(i, end=' ')
