string = input("Enter the string: ")
substring = input("Enter the substring: ")

common = {letter: 0 for letter in string}

for letter in substring:
    try:
        common[letter] += 1
    except KeyError:
        pass

length = 0
for key in common:
    if common[key] > 0:
        length += common[key]
        print(key + ":", common[key])
print("Length:", length)