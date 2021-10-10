# Ternary numeric notation is quite popular in Berland. To telegraph the ternary number the Borze alphabet is used. Digit 0 is transmitted as «.», 1 as «-.» and 2 as «--». You are to decode the Borze code, i.e. to find out the ternary number given its representation in Borze alphabet.

# Input
# The first line contains a number in Borze code. The length of the string is between 1 and 200 characters. It's guaranteed that the given string is a valid Borze code of some ternary number (this number can have leading zeroes).

# Output
# Output the decoded ternary number. It can have leading zeroes.


# input
# .-.--
# output
# 012


# input
# --.
# output
# 20


# input
# -..-.--
# output
# 1012


s = input() #input the string
size = len(s) # it calculate the size of the input string
i = 0        # pointed at starting of the string
j = i+1      
string = ""  #empty string
while j < len(s):  # this loop works till j == size of the input string(s)
    if s[i] == ".": 
        string += "0"
        i = j
        j = i+1
    elif s[i] == "-" and s[j] == ".":
        string += "1"
        i = j+1
        j = i+1
    elif s[i] == "-" and s[j] == "-":
        string += "2"
        i = j+1
        j = i+1
while i < len(s):
    if s[i] == ".":
        string += "0"
    i+=1
print(string)