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

filename = input("Enter file name: ")

file = open(filename)
testcases = int(file.readline())
for i in range(testcases):
  size, search = map(int, file.readline().strip(" ").split(" "))
  array = list(map(int, file.readline().strip(" ").split(" ")))
  print(size, search, array)
  print(str(binarySearch(array, search, size)))




