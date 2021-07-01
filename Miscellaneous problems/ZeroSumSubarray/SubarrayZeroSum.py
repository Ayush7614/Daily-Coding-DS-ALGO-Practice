##Program that find the length of the largest zero sum subarray in an array

#Funciont to find the length 
def maxLength(array):

    #Initialize length
    length = 0

    #Loop through array
    for i in range(len(array)):

        #Initialize sum for every starting point
        sum = 0

        #Loop through subarrays
        for j in range(i, len(array)):

            sum += array[j]

            #Update max length if sum is zero
            if (sum == 0):
                length = max(length, j - i + 1)

    return length


##Driver code
#Initialize array
array = []

#Add integers to array
num1 = int(input("Enter size for the array: "))

for i in range(num1):
    num2 = int(input("Enter integer: "))
    array.append(num2)

#Call function
if (maxLength(array) != 0):
    print("Length of the longest zero sum subarray is ", maxLength(array))
else:
    print("No zero sum subarray found!")


#Enter size for the array: 6
#Enter integer: 12
#Enter integer: 13
#Enter integer: -5
#Enter integer: -8
#Enter integer: 3
#Enter integer: 9
#Length of the longest zero sum subarray is  3
