#An anagram of a string is another string that contains the same characters, only the order of characters can be different

def anagram(str1,str2):
    n1,n2=len(str1),len(str2) 
    if n1!=n2: #checking length of both strings are equal or not
        return 0
    srt1,str2=str1.lower(),str2.lower() #setting the case to lower
    str1,str2=sorted(str1),sorted(str2) #sorting characters

    for i in range (0,n1):
        if str1[i]!=str2[i]:
            return 0
    return 1

str1=str(input("Enter first string:"))
str2=str(input("Enter second string:"))

if anagram(str1,str2):
    print("Strings are anagrams of each other")
else:
    print("Strings are not anagrams of each other")
    
"""
Sample input1:
silent
listen

Output:
Given strings are Anagrams of  each other
-----------------------------------------------
Sample input2:
Hello
World

Output:
Given strings are Not Anagrams of  each other
-----------------------------------------------
"""
