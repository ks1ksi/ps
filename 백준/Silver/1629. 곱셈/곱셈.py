A, B, C = map(int, input().split())

def power(a, b, c):
    if b == 1:
        return a % c
    elif b % 2 == 1:
        x = power(a, b//2 ,c)
        return x * x * a % c
    else:
        x = power(a, b//2, c)
        return x * x % c

print(power(A, B, C))

