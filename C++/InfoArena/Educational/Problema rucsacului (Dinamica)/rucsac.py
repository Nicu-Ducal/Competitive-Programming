with open("rucsac.in") as f:
    n, g = map(int, f.readline().split())
    ob = [(0,0)] + [(int(line.rstrip().split()[0]), int(line.rstrip().split()[1])) for line in f.readlines()]

dp = [[0] * (g + 1) for i in range(2)]

for i in range(1, len(ob)):
    for j in range(1, g + 1):
        if j < ob[i][0]:
            dp[1][j] = dp[0][j]
        elif j >= ob[i][0]:
            dp[1][j] = max(dp[0][j], ob[i][1] + dp[0][j - ob[i][0]])
    dp.pop(0)
    dp.append([0] * (g + 1))

dp.pop()
with open("rucsac.out", "w") as f:
    print(dp[0])