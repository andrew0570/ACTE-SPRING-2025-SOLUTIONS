n=int(input()) #takes in input
nums=list(map(int,input().split()))
maxsum=nums[0] #default variables
currsum=0
start=end=s=0
for i in range(n):
    currsum+=nums[i] #adds each market value to running sum
    if currsum>maxsum: #check if sum is bigger than current max sum
        maxsum=currsum #update max sum
        start=s #update start and end indicies for subarray
        end=i
    if currsum<0: #negative number means sum will not increase
        currsum=0 #reset current sum
        s=i+1 #update starting index
print(maxsum)
print(" ".join(map(str,nums[start:end+1]))) #print subarray
