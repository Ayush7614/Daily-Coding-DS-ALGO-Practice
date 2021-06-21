#Bytelandian gold coins Problem Code: COINS codechef
result=dict()
def maxdollars(n):
    if(n>=0 and n<=11):
        result[n]=n 
        return result[n]
    if n in result:
        return result[n]
    ans=maxdollars(n//2)+maxdollars(n//3)+maxdollars(n//4)
    if(ans>n):
        result[n]=ans
    else:
        result[n]=n 
    return(result[n])
while(1):
    try:
        n=int(input())
        res=maxdollars(n)
        print(res)
    except:
        break
#Example
# input:-12
#output:-13