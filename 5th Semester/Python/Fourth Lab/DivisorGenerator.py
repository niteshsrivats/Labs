number = int(input("Enter a number: "))
divisors = [1]
for i in range(2, int(number / 2) + 1):
    if number % i == 0:
        divisors.append(i)
print(divisors)
