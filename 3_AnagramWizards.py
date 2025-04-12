#Anagram Wizards Solutions
num=int(input()) #takes in number of inputs
stack=[] #creates list
for _ in range(num): #loops for each case
    anagram1, anagram2=input().split('|') #takes in two words
    anagram3=list(anagram1) #makes each word list of characters
    anagram4=list(anagram2)
    list1=anagram3.sort() #sorts each list
    list2=anagram4.sort()
    if (anagram3==anagram4): #checks if sorted lists are same and they are not same word
        stack.append(str(anagram1)+'|'+str(anagram2)+": "+"true")
    else:
        stack.append(str(anagram1)+'|'+str(anagram2)+": "+"false")
for items in stack: #prints answers
    print(items)
