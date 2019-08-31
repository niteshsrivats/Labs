word = "brontosaurus"
counts = dict()
for letter in word:
    try:
        counts[letter] += 1
    except KeyError:
        counts[letter] = 1
print(counts)
