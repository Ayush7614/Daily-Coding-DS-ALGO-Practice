#program to find the digit frequency in an appropriate string
# and the digits are ranging from 0-9

def DigitFrequency(string):
    
    #maintaining a hash table to store 
    #the digit frequency of the occuring digits in the string
    d=dict()
    for i in string:
        #check if the character is digit/not
        if i.isdigit():
            d[i]=string.count(i)
    #sort the hashtable so that the required output will get
    d=dict(sorted(d.items()))
    #print the result from the hash table 
    # in a required format 
    for i in range(10):
        if str(i) in d:
            print(f'{i} is {d[str(i)]} times')
        else:
            print(f'{i} is {0} times')

DigitFrequency("jdjskjd32njs42398sm")