# numcases=int(input())
anslist=[]
# for _ in range(numcases):
d,w=map(int,input().split())
correctwords={}
for i in range(d):
    word=input()
    correctwords[word]=100
for j in range(w):
    for keys in correctwords:
        correctwords[keys]=100
        min=101
    wrongword=input()
    wrongword=list(wrongword)
    for keys in correctwords:
        theword=list(keys)
        if(len(theword)!=len(wrongword)):
            continue
        hemming=0
        for k in range(len(wrongword)):
            if(wrongword[k]!=theword[k]):
                hemming+=1
        correctwords[keys]=hemming
    ans=""
    for keys in correctwords:
        if correctwords[keys]<min:
            min=correctwords[keys]
            ans=keys
    anslist.append(ans)
for items in anslist:
    print(items)