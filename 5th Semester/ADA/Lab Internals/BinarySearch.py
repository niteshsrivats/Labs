def binarySearch(array, search, size):
    min = 0
    max = size - 1
    while min <= max:
        mid = int((min + max)/2)
        if array[mid] == search:
            return 1
        elif array[mid] > search:
            max = mid - 1
        else:
            min = mid + 1
    return -1


size, search = map(int, input(
    "Enter size and search element: ").strip(" ").split(" "))
array = list(map(int, input("Enter the array: ").strip(" ").split(" ")))
print(str(binarySearch(array, search, size)))
