def dpsolve(n,k,coins):
    INF=float('inf')
    dp=[INF]*(K+1) #initialize dp list
    dp[0]=0 #this is the base case of 0 coins needed to make 0
    for coin in coins: #loops through coins in list
        #go backwards to ensure each coin is used only once
        for i in range(K,coin-1,-1):
            if dp[i-coin]!=INF: #make sure we can make (i - coin)
                dp[i]=min(dp[i],dp[i-coin]+1) #get the smaller value for optimal solution
    return dp[K] if dp[K]!=INF else -1  #if K can't be formed then return -1

n,k=map(int,input().split())
coins=list(map(int,input().split()))
print(dpsolve(n,k,coins))
