# Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem

for _ in range(int(input())):
    N, K = map(int, input().split())
    number = input()
    p = list()
    for i in range(len(number)-K):
        product=1
        str = number[i:i+K]
        for ch in str:
            product = product*int(ch)
        p.append(product)
    print(max(p))