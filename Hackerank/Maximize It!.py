def func(temp,l):
    global m_sum,m
    if len(l)==0:
        if temp>m_sum: m_sum = temp%m
        return
    for i in range(len(l[0])):
        crap = ((temp%m)+((l[0][i]**2)%m))%m
        func(crap,l[1:])
        
k,m = map(int,raw_input().split())
l = []
for _ in range(k):
    l.append(map(int,raw_input().split())[1:])

m_sum = 0
temp = 0
for i in range(len(l[0])):
    temp = (l[0][i]**2)%m
    func(temp,l[1:])
    
print(m_sum)
