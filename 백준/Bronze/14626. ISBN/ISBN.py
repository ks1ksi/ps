import sys

input = sys.stdin.readline

s = input()

x = 0
k = 0

for i in range(12):
    t = 1 if i % 2 == 0 else 3
    if s[i] == "*":
        k = t
        continue
    x += t * int(s[i])
    x %= 10

# x + k*star + s[12] === 0 (mod 10)
# k == 1 or 3

ans = (-int(s[12]) - x) % 10
if k == 3:
    ans = ans * 7 % 10
print(ans)
