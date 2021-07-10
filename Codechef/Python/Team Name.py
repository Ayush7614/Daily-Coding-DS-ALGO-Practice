# Problem Link: https://www.codechef.com/FEB21C/problems/TEAMNAME

t = int(input())
for i in range(t):
    n = int(input())
    li = list(input().split())
    di = {}
    for i in li:
        temp = i[1:]
        if temp in di:
            di[temp].append(i[0])
        else:
            di[temp] = [i[0]]
    di1 = list(di.keys())
    sumi = 0
    for i in range(len(di)):
        for j in range(i+1, len(di)):
            kl1 = di[di1[i]]
            kl2 = di[di1[j]]
            temp = len(set(kl1+kl2))
            sumi+=(temp-len(di[di1[i]]))*(temp-len(di[di1[j]]))
    print(2*sumi)
    
    