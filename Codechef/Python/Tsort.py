vin = int(input())
suy = []
for i in range(vin):
    suy.append(int(input()))
suy.sort(reverse=False)
for nums in suy:
    print(nums)
