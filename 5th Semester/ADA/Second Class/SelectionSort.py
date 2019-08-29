import time
import numpy as np
import matplotlib as mplt
from matplotlib import pyplot as plt

totalComparisions = 0
def selection_sort(array, size):
    global totalComparisions
    for i in range(size):
        position = i
        for j in range(i + 1, size):
            totalComparisions += 1
            if array[position] > array[j]:
                position = j
        array[i], array[position] = array[position], array[i]
    return array

def runOnInput():
    array = list(map(int, input("Enter numbers: ").strip(" ").split(" ")))
    size = len(array)
    print("Sorted Array: ", selection_sort(array, size))
    print("Total Comparisions:", totalComparisions)

def draw(times, sizes):
    plt.title("Selection Sort")
    plt.axis([0, max(sizes) * 1.1, 0, np.amax(times) * 1.1])
    # plt.scatter(sizes, total_time)
    plt.plot(sizes, times)
    plt.show()

def benchmark():
    total_times = list()
    sizes = [x for x in range(100, 2001, 100)]
    for size in sizes:
        array = np.array(np.random.random_sample(size) * 10000, dtype='i4')
        start_time = time.time()
        selection_sort(array, size)
        total_times.append(time.time() - start_time)

    draw(total_times, sizes)

# 2 74 38 87 95 42 88 58 8 23 62 83 12 19 28 38 47 6 31 94
# Total Comparisions: 190
runOnInput()
