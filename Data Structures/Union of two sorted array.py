a=list(map(int,input('Enter elements of first list:').split()))
b=list(map(int,input('Enter elements of second list:').split()))

A=list(set(a)|set(b))
B=list(set(a)&set(b))

print('Union of the arrays:',A)


#Input given a= 1 2 3 4  and  b = 2 3 4 5  output:-  union = 1 2 3 4 5
