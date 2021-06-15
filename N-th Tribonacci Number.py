def Tribonacci_Number(n):
    if n == 0 :
        return 0
    elif n == 1 or n == 2 :
        return 1
    else :
        return (Tribonacci_Number(n-1) + Tribonacci_Number(n-2) + Tribonacci_Number(n-3))

N = input("Enter n for find nth Tribonacci Number : ")

print(N,"th Tribonacci Number is : ",Tribonacci_Number(int(N)))