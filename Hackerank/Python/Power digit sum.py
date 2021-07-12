# Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler016/problem

for _ in range(int(input())):
    print(sum((map(int, str(2**int(input()))))))
