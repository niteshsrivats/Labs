def getMap(keys, values):
    return {keys[i]: values[i] for i in range(len(keys))}


def getStringInputList(message):
    return list(map(str, input(message).strip(" ").split(" ")))


def getIntegerInputList(message):
    return list(map(int, input(message).strip(" ").split(" ")))


library = getMap(getStringInputList("Enter Books: "),
                 getIntegerInputList("Enter Prices: "))

requirements = getMap(getStringInputList("Enter Required Books: "),
                      getIntegerInputList("Enter Quantities: "))

total = 0
for key in requirements:
    try:
        total += library[key] * requirements[key]
    except KeyError:
        print("Book " + key + " not found.")
print("Total: " + str(total))
