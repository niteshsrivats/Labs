for i in range(50):
    mod3 = i % 3 == 0
    mod5 = i % 5 == 0
    if mod5 and mod3:
        print("FizzBuzz")
    elif mod3:
        print("Fizz")
    elif mod5:
        print("Buzz")
    else:
        print(i)
