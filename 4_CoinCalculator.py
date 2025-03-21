N,K=map(int,input().split()) #take in input
coins=list(map(int,input().split()))
coins.sort(reverse=True) #sort coins in decending order
found=False
sum=0
for i in range(len(coins)):
    if coins[i]>K: #no point in checking coins that are greater
        continue
    elif coins[i]==K: #automatically stop when there is a coin of K
        print("1")
        found=True
        break
    sum=coins[i] #set sum to current value < K
    count=1 #counts coins
    j=i+1 #another index variable for indicies after current index
    while(sum<K and j<len(coins)): #loops to add up values after current index
        if sum+coins[j]<=K:
            sum+=coins[j] #loops to add up values after current index
            count+=1 #update num of coins
        j+=1 #update index
    if sum==K: #make sure sum is not greater than K
        print(count)
        found=True
        break
    #otherwise continue to loop for each coin until you
    #get correct combination of numbers
if not(found):
    print("-1")
