import numpy as np

# capacity = int(input("Enter capacity: "))
# weights = list(map(int, input("Enter weights: ").strip(" ").split(" ")))
# values = list(map(int, input("Enter values: ").strip(" ").split(" ")))

subset = [10, 20, 30, 25, 5]

size = len(subset)


def sumOfSubsets(set, sum, index=0, subset=[]):
    if index == size:
        return
    if set[index] == sum:
        subsetCopy = subset.copy()
        subsetCopy.append(set[index])
        print(subsetCopy)
        sumOfSubsets(set, sum, index + 1, subset)
    elif sum - set[index] < 0:
        sumOfSubsets(set, sum, index + 1, subset)
    elif sum - set[index] > 0:
        subsetCopy = subset.copy()
        subsetCopy.append(set[index])
        sumOfSubsets(set, sum - set[index], index + 1,
                     subsetCopy) or sumOfSubsets(set, sum, index + 1, subset)


sumOfSubsets(subset, 30)
