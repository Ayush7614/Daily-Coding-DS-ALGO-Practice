
#do practice the question at https://www.codechef.com/START5A/problems/CYCLICQD
#Question About 
'''
You are given the sizes of angles of a simple quadrilateral (in degrees) 
A, B, C and D, in some order along its perimeter. 
Determine whether the quadrilateral is cyclic.
'''
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

# last 1 hour

#user Input  

def solve():
    a,b,c,d = mp()
    if a+c == b+d == 180:
        pr('YES')
    else:
        pr('NO')

#Input
for _ in range(inp()):
    solve()


'''
Example:
Input:
3
10 20 30 300        #case 1
10 20 170 160       #case 2
179 1 179 1         #case 3

Output:
NO
YES
NO

Explanation:
case 1: The sum of two opposite angles A+C=10∘+30∘≠180∘.

case 2: The sum of two opposite angles A+C=10∘+170∘=180∘ and B+D=20∘+160∘=180∘.

case 3: The sum of two opposite angles B+D=1∘+1∘≠180∘.
'''
