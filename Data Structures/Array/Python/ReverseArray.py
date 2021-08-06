arr = []
arr=[int(x) for x in input().split()]
print("Original array: ")    
for i in range(0, len(arr)):    
    print(arr[i]),     
print("Array in reverse order: ")    
#Loop through the array in reverse order    
for i in range(len(arr)-1, -1, -1):     
    print(arr[i]),
