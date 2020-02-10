import sys 
array = list(map(int, input("Enter an array of numbers: ").strip(" ").split(" ")))
max = array[0]
for element in array:
 if element > max:
  max = element

print("Max: " + str(max))






