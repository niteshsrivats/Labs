array = list(map(int, input("Enter numbers: ").strip(" ").split(" ")))
k = int(input("Enter required number of smallest numbers: ").strip(" "))
size = len(array)

for i in range(k):
    position = i
    for j in range(i + 1, size):
        if array[position] > array[j]:
            position = j
    array[i], array[position] = array[position], array[i]
print(k, "Smallest numbers:", array[k - 1])
