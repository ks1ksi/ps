import sys

input = sys.stdin.readline
N, r, c = map(int, input().split())

def solve(row, col, N, ans):
    if row == r and col == c:
        print(ans)
    else: 
        if r < row + 2**(N - 1) and c < col + 2**(N - 1):
            solve(row, col, N - 1, ans)
            
        elif r < row + 2**(N - 1) and c >= col + 2**(N - 1):
            solve(row, col + 2**(N - 1), N - 1, ans + 2**(2*N - 2))
            
        elif r >= row + 2**(N - 1) and c < col + 2**(N - 1):
            solve(row + 2**(N - 1), col, N - 1, ans + 2**(2*N - 2)*2)
            
        elif r >= row + 2**(N - 1) and c >= col + 2**(N - 1):
            solve(row + 2**(N - 1), col + 2**(N - 1), N - 1, ans + 2**(2*N - 2)*3)
        
        
solve(0, 0, N, 0)
