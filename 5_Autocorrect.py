anslist=[]
d,w=map(int,input().split())
correctwords={}
for i in range(d): #creates dictionary of correct words
    word=input()
    correctwords[word]=100
for j in range(w):
    for keys in correctwords: #sets default min hemming distance
        correctwords[keys]=100
        min=101
    wrongword=input() #takes in incorrect words
    wrongword=list(wrongword)
    for keys in correctwords:
        theword=list(keys) #gets each correct word from dictionary to compare to wrong word
        if(len(theword)!=len(wrongword)): #if lengths are different, no point in checking
            continue
        hemming=0
        for k in range(len(wrongword)): #loops through each character and checks number of characters that are different
            if(wrongword[k]!=theword[k]):
                hemming+=1 #count for number of substitutions
        correctwords[keys]=hemming #gets hemming distance between each correct word and wrong word
    ans=""
    for keys in correctwords: #finding smallest hemming distance
        if correctwords[keys]<min:
            min=correctwords[keys] #update each time there is smaller hemming distance
            ans=keys #records word
    anslist.append(ans)

for items in anslist:
    print(items)
