
value=[1,2,5,7,8,9,11,20]
number = int(input("Enter the Number to be search "))
num_val=len(value)-1

def binary_search(value,first,end,val):
    if end >= 1:
        mid = first + (end-1)//2
        print("\n")

        if value[mid] == val:
            return mid
        elif value[mid] >= val:
            return binary_search(value,first,mid-1,val)
        elif value[mid] <= val:
            return binary_search(value, mid +1,end ,val)


result = binary_search(value,0,num_val,number)

if result != -1:
    print(number," is found at ", result ," position")
else :
    print(" No found ")
'''
  Test case:-
   number = 20
   1st mid = 3 , then value[3] = 7
                   since 7< 20
                   therefore first = mid + 1 = 4
                              
   2nd mid = 7 , then value[7] = 20
                    value = 20
                    Number is found

'''
