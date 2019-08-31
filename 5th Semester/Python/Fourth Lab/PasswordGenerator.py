import random


def scramble(stringList):
    length = len(stringList)
    for i in range(1000):
        first, second = random.randint(
            0, length - 1), random.randint(0, length - 1)
        stringList[first], stringList[second] = stringList[second], stringList[first]
    return "".join(stringList)


def passwordGenerator(minLength, maxLength):
    lowerCaseCount = random.randint(1, maxLength - 3)
    upperCaseCount = random.randint(1, maxLength - lowerCaseCount - 2)
    numbersCount = random.randint(
        1, maxLength - lowerCaseCount - upperCaseCount - 1)
    specialCharacterCount = random.randint(
        1, maxLength - lowerCaseCount - upperCaseCount - numbersCount)
    password = [chr(random.randint(97, 122))
                for x in range(lowerCaseCount)]
    password.extend([chr(random.randint(32, 48))
                     for x in range(specialCharacterCount)])
    password.extend([chr(random.randint(65, 90))
                     for x in range(upperCaseCount)])
    password.extend([str(random.randint(0, 9)) for x in range(numbersCount)])
    return scramble(password)


print(passwordGenerator(8, 15))
