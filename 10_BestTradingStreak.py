n=int(input())
nums=list(map(int,input().split()))
maxsum=nums[0]
currsum=0
start=end=s=0
for i in range(n):
    currsum+=nums[i]
    if currsum>maxsum:
        maxsum=currsum
        start=s
        end=i
    if currsum<0:
        currsum=0
        s=i+1
print(maxsum)
print(" ".join(map(str,nums[start:end+1])))