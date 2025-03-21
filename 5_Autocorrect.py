anslist=[]
d,w=map(int,input().split())
correctwords={}
for i in range(d): #creates dictionary of correct words
    word=input()
    correctwords[word]=100
for j in range(w):
    for keys in correctwords: #sets default min hemming distance
        correctwords[keys]=100
        minimum=101
    wrongword=input() #takes in incorrect words
    wrongword=list(wrongword)
    for keys in correctwords:
        theword=list(keys) #gets each correct word from dictionary to compare to wrong word
        hemming=0
        hemming+=abs(len(theword)-len(wrongword)) #accounts for additional letters
        for k in range(min(len(theword),len(wrongword))): #loops through each character and checks number of characters that are different
            if(wrongword[k]!=theword[k]):
                hemming+=1 #count for number of substitutions
        correctwords[keys]=hemming #gets hemming distance between each correct word and wrong word
    ans=""
    for keys in correctwords: #finding smallest hemming distance
        if correctwords[keys]<minimum:
            minimum=correctwords[keys] #update each time there is smaller hemming distance
            ans=keys #records word
    anslist.append(ans)
for items in anslist:
    print(items)
