# Python code to demonstrate
# to calculate difference
# between adjacent elements in list

# Size of List
n = int(input("Enter the size of List : "))

# initialising empty list
ini_list = []  

# Taking n elements input in list
for i in range(0,n):
    ini_list.append(int(input()))

# printing iniial_list
print("intial_list", str(ini_list))
  
# Calculating difference list
diff_list = []
for x, y in zip(ini_list[0::], ini_list[1::]):
    diff_list.append(y-x)
      
# printing difference list
print ("difference list: ", str(diff_list))
