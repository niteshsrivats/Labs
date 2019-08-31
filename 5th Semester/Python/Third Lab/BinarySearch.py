def binary_search(array, search):
    low, high = 0, len(array) - 1
    while low <= high:
        mid = int((low + high) / 2)
        if array[mid] == search:
            return True
        elif array[mid] > search:
            high = mid - 1
        else:
            low = mid + 1
    return False


array = list(map(int, input("Enter numbers: ").strip(" ").split(" ")))
search = int(input("Enter search element: ").strip(" "))
print("Found: ", binary_search(array, search))
