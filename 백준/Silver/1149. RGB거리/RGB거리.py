T = int(input())
rgb = [list(map(int, input().split())) for _ in range(T)]
rgbStreet = [[0] * 3 for _ in range(T)]

rgbStreet[0] = rgb[0]

for i in range(1, T):
    rgbStreet[i][0] = min(rgbStreet[i-1][1], rgbStreet[i-1][2]) + rgb[i][0]
    rgbStreet[i][1] = min(rgbStreet[i-1][0], rgbStreet[i-1][2]) + rgb[i][1]
    rgbStreet[i][2] = min(rgbStreet[i-1][0], rgbStreet[i-1][1]) + rgb[i][2]

print(min(rgbStreet[T-1]))
