# python3 file

n = int(input())  # taking number of test cases as input
for i in range(n):
    w = input()  # taking a word as input
    if(len(w) <= 10):  # if length of the word is less than or equal to 10
        print(w)  # we print that word directly
    else:
        # extracting first character and last character with length of string in between
        new_word = w[0]+str(len(w)-2)+w[len(w)-1]
        print(new_word)  # printing new word
