t = int(input().strip())
for _ in range(t):
    n, x = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    prefix = [0]*(n+1)
    for i in range(n):
        prefix[i+1] = prefix[i] ^ a[i]
    dp = [[False]*(2**20) for _ in range(3)]
    dp[0][0] = True
    for i in range(1, n+1):
        for j in range(2**20):
            for k in range(1, 3):
                if j >= prefix[i]:
                    dp[k][j] |= dp[k-1][j^prefix[i]]
        dp[0][prefix[i]] = True
    for i in range(x, 2**20):
        if dp[2][i]:
            print(2)
            break
    else:
        print(-1 if prefix[-1] > x else 1)