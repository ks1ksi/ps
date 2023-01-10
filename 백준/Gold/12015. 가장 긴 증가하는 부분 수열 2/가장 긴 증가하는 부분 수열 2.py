N = int(input())
arr = list(map(int, input().split()))
arr.insert(0, 0)
checkLength = [0]


def binarySearch(array, value, low, high):
    if low > high:
        return low
    mid = (low+high) // 2
    if array[mid] > value:
        return binarySearch(array, value, low, mid-1)
    elif array[mid] < value:
        return binarySearch(array, value, mid+1, high)
    else:
        return mid


for i in range(1, N + 1):
    targetIndex = binarySearch(checkLength, arr[i], 0, len(checkLength) - 1)
    if targetIndex >= len(checkLength):
        targetIndex -= 1
    if checkLength[targetIndex] >= arr[i]:
        checkLength[targetIndex] = arr[i]
    else:
        if targetIndex == len(checkLength) - 1:
            checkLength.append(arr[i])


print(len(checkLength) - 1)

