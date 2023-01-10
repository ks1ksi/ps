import sys
from functools import cmp_to_key
input = sys.stdin.readline

K, N = map(int, input().split())
numlist = [input().rstrip() for _ in range(K)]

def compare(a, b):
    if a == b:
        return 0
    if len(a) >= len(b):
        for i in range(len(b)):
            if a[i] > b[i]:
                return -1
            elif a[i] < b[i]:
                return 1
        return compare(a[len(b):], b)
    else:
        for i in range(len(a)):
            if a[i] > b[i]:
                return -1
            elif a[i] < b[i]:
                return 1
        return compare(a, b[len(a):])

# def sort_1(x):
#     p = 8
#     ret = 0
#     for c in x:
#         ret += int(c) * 10 ** p
#         p -= 1
#     while p >= 0:
#         ret += int(x[0]) * 10 ** p
#         p -= 1
#     return ret + int(x[-1])

s_list = sorted(numlist, key=cmp_to_key(compare))
m = ''
for i in s_list:
    if len(i) > len(m):
        m = i
    elif int(i) > int(m):
        m = i

cnt = N - K
for i in s_list:
    if i == m:
        while cnt > 0:
            print(i, end='')
            cnt -= 1
    print(i, end='')
