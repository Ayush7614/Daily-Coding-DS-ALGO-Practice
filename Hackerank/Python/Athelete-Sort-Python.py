#!/bin/python3
#Athlete Sort - HackerRank problem solution by - Bhavesh Joshi - @Witty-Panda (Github)
#HackerRank link - https://www.hackerrank.com/challenges/python-sort-sort/problem

'''
Problem - 
You are given a spreadsheet that contains a list of  athletes and their details (such as age, height, weight and so on). You are required to sort the data based on the th attribute and print the final resulting table.

Note: If two attributes are the same for different rows, for example, if two atheletes are of the same age, print the row that appeared first in the input.

Input Format

The first line contains N and M separated by a space.
The next N lines each contain M elements.
The last line contains K.

Constraints
1<=N,M<=1000
0<=K<=M
Each element <= 1000

Output Format

Print the N lines of the sorted table. Each line should contain the space separated elements. Check the sample below for clarity.

Sample Input 0

5 3
10 2 5
7 1 0
9 9 9
1 23 12
6 5 9
1
Sample Output 0

7 1 0
10 2 5
6 5 9
9 9 9
1 23 12
Explanation 0

The details are sorted based on the second attribute, since K is zero-indexed.
'''
N, M = map(int, input().split())
NUMS = [list(map(int, input().split())) for i in range(N)]
K = int(input())

NUMS.sort(key=lambda x: x[K])

for line in NUMS:
    print(*line, sep=' ')