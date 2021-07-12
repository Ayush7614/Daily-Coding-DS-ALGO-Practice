#!/bin/python3
import math
import os
import random
import re
import sys

# Complete the caesarCipher function below.
def caesarCipher(s, k):
    temp=[]
    for char in s:
        temp.append(ord(char))
    
    for i in range(n):
        if 65<=temp[i]<=90:
            temp[i]=(65+(temp[i]-65+k)%26)
        elif 97<=temp[i]<=122:
            temp[i]=(97+(temp[i]-97+k)%26)
    return "".join(map(chr,temp))
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    s = input()
    k = int(input())
    result = caesarCipher(s, k)
    fptr.write(result + '\n')
    fptr.close()
