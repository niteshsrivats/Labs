import sys

amount = int(input("Enter Amount: "))
coins = list(map(int, input('Enter Denominations: ').strip(" ").split(" ")))

change = dict()

for i in range(1, coins[0]):
    change[i] = [sys.maxsize, []]

for i in range(coins[0], amount + 1):
    num_coins = int(i / coins[0])
    change[i] = [num_coins, [coins[0]] * num_coins]
coins.pop(0)

for coin in coins:
    change[coin] = [1, [coin]]

for coin in coins:
    for i in range(coin + 1, amount + 1):
        if change[i - coin][0] + 1 <= change[i][0]:
            change[i] = [change[i - coin][0] + 1, change[i - coin][1].copy() + [coin]]
    # print(change)
print("Number of coins:", change[amount][0], "Coins:", change[amount][1])
