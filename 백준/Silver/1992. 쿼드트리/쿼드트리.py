N = int(input())
image = [list(map(int, input())) for _ in range(N)]


def cut(num, image):
    size = len(image)
    newImage = []
    if num == 0:  # 왼쪽 위
        for i in range(size//2):
            newImage.append(image[i][:size//2])
    elif num == 1:  # 오른쪽 위
        for i in range(size//2):
            newImage.append(image[i][size//2:])
    elif num == 2:  # 왼쪽 아래
        for i in range(size//2):
            newImage.append(image[i + size//2][:size//2])
    elif num == 3:  # 오른쪽 아래
        for i in range(size//2):
            newImage.append(image[i + size//2][size//2:])
    return newImage


def same(image):
    n = len(image)
    check = image[0][0]
    for i in image:
        for j in range(n):
            if i[j] != check:
                return False
    return True
        

def compress(image):
    if len(image) == 1:
        print(image[0][0], end='')
        return

    lu = cut(0, image)
    ru = cut(1, image)
    ld = cut(2, image)
    rd = cut(3, image)

    if (lu == ru == ld == rd) and same(lu):
        print(lu[0][0], end='')

    else:
        print('(', end='')
        compress(lu)
        compress(ru)
        compress(ld)
        compress(rd)
        print(')', end='')


compress(image)