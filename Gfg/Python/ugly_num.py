# DESCRIPTION
# Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
# The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
# Through this python code we can find out the ugly number at Nth position
# Example :  
            # Input  : n = 7
            # Output : 8

            # Input  : n = 15
            # Output : 24

            

# Function to divide number by greatest divisible of 2,3,5 and  return the last result
def Divide(a, b):
    while a % b == 0:
        a = a / b
    return a

# Function to find whether the number is ugly or not
def is_ugly_num(no):
    no = Divide(no, 2)
    no = Divide(no, 3)
    no = Divide(no, 5)
    return 1 if no == 1 else 0

# Function to find Nth ugly number
def Nth_ugly_num(n):
    # Initializing the list with 1 as it's not bound by the rule of prime factors by 2,3 or 5
    lst = [1]

    # Initializing the counter with 1 because one ugly number is already stored in the list
    count = 1
    i = 1

    # Loop until we reach to the Nth ugly number
    while count < n:
        i += 1

        # to check the naturally occcuring number is ugly or not, then appending it to the end of the list and updating the counter by one
        if is_ugly_num(i):
            lst.append(i)   
            count += 1

    # Printing the list of ugly numbers till the Nth ugly number
    print(*lst)

    # Returning Nth ugly number
    return lst[-1]

# Main function
def main():

    # Taking input from user 
    num = int(input("Enter position for ugly number : "))
    # Passing the number to Nth_ugly_num function and storing return value in variable un
    un = Nth_ugly_num(num)
    print(f"{num}th Ugly Number is : {un}")

# To check if the file contains the main function and then calling the main function
if __name__ == '__main__':
    main()

# COMPLEXITY:
# Space : O(1)
# Time :O(N)

# OUTPUT
            # Input  : 
                # Enter position for ugly number : 10 
            # Output : 
                # 10th ugly number is : 12

            # Input  : 
                # Enter position for ugly number : 150
            # Output : 
                # 10th ugly number is : 5832 