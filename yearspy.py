print("Welcome\n")
print("The Menu\n")
print("1- Into Minutes\n")
print("2- Into Hours\n")
print("3- Into Days\n")
print("4- Into Months\n")
print("5- Into Seconds\n")
c=int(input("Enter the choice : "))
x=int(input("\nEnter the year value : "))

if x is 1:
    print(x," Years = ",x*525600," Minutes")
elif x is 2:
    print(x," Years = ",x*8760," Hours")
elif x is 3:
    print(x," Years = ",x*365," Days")
elif x is 4:
    print(x," Years = ",x*12," Months")
elif x is 5:
    print(x," Years = ",x*3153600," Seconds")
else:
    print("Invalid input")