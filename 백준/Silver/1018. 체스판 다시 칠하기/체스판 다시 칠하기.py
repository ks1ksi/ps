R, C = map(int, input().split())
chessBoard = [input() for _ in range(R)]
minRet = 987654321


def checkChessBoard(row, col):
    ret = 0
    firstSquare = chessBoard[row][col]
    for i in range(row, row + 8):
        if i % 2 == 0:
            for j in range(col, col + 8):
                if j % 2 == 0 and chessBoard[i][j] != firstSquare:
                    ret += 1
                elif j % 2 == 1 and chessBoard[i][j] == firstSquare:
                    ret += 1
        else:
            for j in range(col, col + 8):
                if j % 2 == 0 and chessBoard[i][j] == firstSquare:
                    ret += 1
                elif j % 2 == 1 and chessBoard[i][j] != firstSquare:
                    ret += 1
    if ret > 32:
        ret = 64 - ret
    return ret


for i in range(R - 7):
    for j in range(C - 7):
        ret = checkChessBoard(i, j)
        if ret < minRet:
            minRet = ret

print(minRet)
