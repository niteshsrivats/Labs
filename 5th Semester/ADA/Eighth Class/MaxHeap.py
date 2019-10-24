size = int(input("Enter size of array: "))
array = list(map(int, input("Enter the array: ").strip(" ").split(" ")))
array = [0] + array


def checkMaxHeap(array, size):
    for i in range(1, int(size / 2)):
        if array[i] < max(array[2 * i], array[(2 * i) + 1]):
            return False
    return True


print("Max Heap:", checkMaxHeap(array, size))
