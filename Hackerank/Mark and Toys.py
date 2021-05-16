# Link of the Problem: https://www.hackerrank.com/challenges/mark-and-toys/problem
import math
import os
import random
import re
import sys

def maximumToys(prices, k):
    prices.sort()
    s = 0
    c = 0
    for i in range(len(prices)):
        if s+prices[i]<=k:
            s+=prices[i]
            c+=1
    return c

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    prices = list(map(int, input().rstrip().split()))

    result = maximumToys(prices, k)

    fptr.write(str(result) + '\n')

    fptr.close()
