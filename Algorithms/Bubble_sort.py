#BUBBLE SORTING:
nlist=eval(input("enter a list"))
for passnum in range(len(nlist)-1,0,-1):
    for i in range(passnum):
        if nlist[i]>nlist[i+1]:
            temp = nlist[i]
            nlist[i] = nlist[i+1]
            nlist[i+1] = temp
print(nlist)

#enter a list[5,6,9,34,1,0,4]
#Output=
#[0, 1, 4, 5, 6, 9, 34]
