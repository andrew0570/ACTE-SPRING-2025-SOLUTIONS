#Coin Calculator Solution
numcoins,amount=map(int,input().split()) 
udictcoins={}
coinstack=map(int,input().split())
for coin in coinstack:
    if(not(coin in udictcoins.keys())):
        udictcoins[coin]=1
    else:
        udictcoins[coin]=udictcoins[coin]+1
dictcoins=dict(sorted(udictcoins.items(),reverse=True))
count=0
sum=0
for keys in dictcoins:
    if(keys<=amount and keys!=0):
        tempc=0
        while(tempc<dictcoins[keys] and sum+keys<=amount):
            sum=sum+keys
            count=count+1
            tempc=tempc+1
print(count)