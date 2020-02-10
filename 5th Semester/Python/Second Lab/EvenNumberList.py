numbers = list(map(int, input("Enter numbers: ").strip(" ").split(" ")))
evens = list()
for number in numbers:
    if number % 2 == 0:
        evens.append(number)
print(evens)
