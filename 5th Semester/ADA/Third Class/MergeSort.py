totalComparisions = 0
def mergeSort(array, size):
    if size > 1:
        mid = int(size / 2)
        left = mergeSort(array[:mid], mid)
        right = mergeSort(array[mid:], size - mid)
        return merge(left, right)
    return array

def merge(left, right):
    global totalComparisions
    temp = list()
    while left and right:
        totalComparisions += 1
        if left[0] < right[0]:
            temp.append(left.pop(0))
        else:
            temp.append(right.pop(0))
    for number in left:
        temp.append(number)
    for number in right:
        temp.append(number)
    return temp

def runOnInput():
    array = list(map(int, input("Enter numbers: ").strip(" ").split(" ")))
    size = len(array)
    print("Sorted Array: ", mergeSort(array, size))
    print("Total Comparisions:", totalComparisions)

# 2 74 38 87 95 42 88 58 8 23 62 83 12 19 28 38 47 6 31 94
# Total Comparisions: 64
runOnInput()
