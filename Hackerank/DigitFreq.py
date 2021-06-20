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


#Input Code
str=input()
DigitFrequency(str)

'''
if input string is as2dfl21kji5e9mc


0 is 0 times
1 is 1 times
2 is 2 times
3 is 0 times
4 is 0 times
5 is 1 times
6 is 0 times
7 is 0 times
8 is 0 times
9 is 1 times
'''