str = input()
exp = input()
l = len(exp)
ans = []

for i in str:
    ans.append(i)
    if ans[-l:] == list(exp):
        for _ in range(l):
            ans.pop()

if not ans:
    print("FRULA")
else:
    print(''.join(ans))