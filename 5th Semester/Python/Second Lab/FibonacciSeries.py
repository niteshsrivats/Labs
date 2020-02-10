limit = int(input("Enter number of terms: "))
first, second = 0, 1
print(first, second, end=" ")
for i in range(2, limit):
    first, second = second, first + second
    print(second, end=" ")
print()
