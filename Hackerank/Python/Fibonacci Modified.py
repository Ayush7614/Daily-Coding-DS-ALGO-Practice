#!/bin/python

import math
import os
import random
import re
import sys

# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):
    a = t1;
    b = t2;
    c = t1+ (t2*t2);
    count = 3;
    if (n == 1):
        return t1;
    elif (n == 2):
        return t2;
    elif(n == 3):
        return c;
    else:
        while(count < n):
            count = count+ 1;
            a = b;
            b = c;
            c = a + b*b;
    return c;


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t1T2n = raw_input().split()

    t1 = int(t1T2n[0])

    t2 = int(t1T2n[1])

    n = int(t1T2n[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()
