demo = {"Chuck": 1, "Annie": 42, "Jan": 200}
size = len(demo)
sorted_keys = sorted(demo)
print("{", end="")
for i in range(size):
    print("'" + sorted_keys[i] + "':", demo[sorted_keys[i]], end="")
    if i != size - 1:
        print(end=", ")
print("}")
