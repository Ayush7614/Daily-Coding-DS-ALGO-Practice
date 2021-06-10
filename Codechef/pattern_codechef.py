for i in range(int(input())):
    k=int(input())
    for i in range(k):
        print((" ")*(k-i-1),end="")
        print((i+1)*"(",end="")
        print("*",end="")
        print((i+1)*")",end="")
        print()
