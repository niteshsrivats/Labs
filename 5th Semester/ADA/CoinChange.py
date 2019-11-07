import sys

# amount = int(input())
# coins = list(map(int, input()))

amount = 11
coins = [1, 2, 5]

change = dict()

for i in range(1, coins[0]):
    change[i] = sys.maxsize

for i in range(coins[0], amount + 1):
    change[i] = int(i/coins[0])
coins.pop(0)

for coin in coins:
    change[coin] = 1

# print(change)

for coin in coins:
    for i in range(coin + 1, amount + 1):
        change[i] = min(change[i - coin] + 1, change[i])
    # print(change)

print(change[amount])