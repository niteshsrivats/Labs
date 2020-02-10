totalComparisions = 0
def quickSort(array, low, high):
    if low < high:
        index = partition(array, low, high)
        quickSort(array, low, index - 1)
        quickSort(array, index + 1, high)

def partition(array, low, high):
    global totalComparisions
    pivot = array[high]
    i = low
    for j in range(low, high):
        totalComparisions += 1        
        if (array[j] < pivot):
            if i != j:
                array[i], array[j] = array[j], array[i]
            i += 1
    array[i], array[high] = array[high], array[i]
    return i

def runOnInput():
    array = list(map(int, input("Enter numbers: ").strip(" ").split(" ")))
    size = len(array)
    quickSort(array, 0, size - 1)
    print("Sorted Array: ", array)
    print("Total Comparisions:", totalComparisions)

# 2 74 38 87 95 42 88 58 8 23 62 83 12 19 28 38 47 6 31 94
# Total Comparisions: 72
runOnInput()
