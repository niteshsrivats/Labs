strings = list(map(str, input("Enter strings: ").strip(" ").split(" ")))
strings.reverse()
print(strings)
for i in range(len(strings)):
    strings[i] = strings[i][::-1]
print(strings)
