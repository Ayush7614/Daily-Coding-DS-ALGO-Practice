# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())
arr = list(map(int, input().split()))
weights = list(map(int, input().split()))
print(round(sum([arr[x]*weights[x] for x in range(len(arr))]) / sum(weights), 1))
