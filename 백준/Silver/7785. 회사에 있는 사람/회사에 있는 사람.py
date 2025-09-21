import sys

input = sys.stdin.readline

n = int(input())

st = set()

for _ in range(n):
    name, command = input().split()
    if command == "enter":
        st.add(name)
    else:
        st.remove(name)

lst = list(st)
lst.sort(reverse=True)

for name in lst:
    print(name)
