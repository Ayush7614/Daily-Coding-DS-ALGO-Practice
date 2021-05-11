#!/bin/python3
import math
import os
import random
import re
import sys

# Complete the pangrams function below.
ascii_array = []
def pangrams(s):
    lower_s = s.lower()
    for i in range(len(lower_s)):
        ascii_array.append(ord(lower_s[i]))
    for i in range(97,123):
        if i not in ascii_array:
            return "not pangram"
    return 'pangram'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = pangrams(s)
    fptr.write(result + '\n')
    fptr.close()
