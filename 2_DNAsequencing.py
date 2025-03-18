#DNA Sequencing Solution
seq=list(input()) #takes input and separates into list of characters
dictletters={} #creates dictionary 
for chars in seq: #loops through all characters in seq
    if not(chars in dictletters): #creates key value pair if not already existent
        dictletters[chars]=1
    else:
        dictletters[chars]+=1 #adds one to already existing key value pair
greatest=0
greatletter='G'
for keys in dictletters: #loops through dictionary values
    if (dictletters[keys]>greatest): #checks if it is bigger than current greatest
        greatest=dictletters[keys] #records key
        greatletter=keys #records count
print(str(greatletter)+":"+str(greatest)) #formatted output