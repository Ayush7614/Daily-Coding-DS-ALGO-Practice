def fact(n):
    if (n == 1):
        return n;
    else:
        return n*fact(n-1);


test = int(input())
for i in range (0,test):
    val = int(input())
    print(fact(val))
