def solve():
    s=input()
    s1=s;s1=s1.split('0')
    
    ans=0
    for x in s1: 
        if('1' in x):ans+=1
    
    curSegment=s[0]
    segs=[]
    for chara in s[1:]:
        if chara==curSegment[-1]:
            curSegment+=chara  
        else:
            segs.append(curSegment)  
            curSegment=chara  


    segs.append(curSegment)

    for x in range(1,len(segs)-1):
        if('0' in segs[x] and '1' in segs[x-1] and '1' in segs[x+1]):
            ans+=1

    print(ans)
    return

t=int(input())

while(t>0):
    solve()
    t-=1
