num = int(input())
suy = []

for i in range(num):
    suy.append(int(input()))

suy.sort()

for i in range(num):
    suy[i] = suy[i]*(num-i)

print(max(suy))
