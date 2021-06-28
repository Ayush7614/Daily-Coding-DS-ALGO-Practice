


fact=1   #initalizing the variable
number=int(input())  #inputs taking from the user
i=number  #assigning the value
while(i>0):  #iterating the looop for getting digfferent value of i
    fact=fact*i   #performing th ecalculation
    i=i-1         #decrementing the value of i
print("The value is ",fact)   #printing the value of fact
'''
 Step 1 :- It will take input from user.
 Step 2 :- Then , i will be assigned with the value 
 Step 3 :- After that, loop will be called to fetch the different  value of i
 Step 4 :- Perform the calculation,
 Step 5 :- Give the value .
 
 If user give input as 5 then this value will be asssigned to i and loop will be called.
 Loop will check the condition that whether it satisfy the condition or not.
 
    CASE 1 :- (5 > 0)  is true so it will go through the loop
        so fact = fact * i = 1 * 5 = 5
        then i = i-1 =5-1 = 4 
        so we get here two value fist one is fact =  and i= 4.
 
    CASE 2 :- (4 > 0)  is true so it will go through the loop
        so fact = fact * i = 5 * 4 = 20
        then i = i-1 = 4 -1 = 3 
        so we get here two value fist one is fact = 20 and i= 3.
        
    CASE 3 :- (3 > 0)  is true so it will go through the loop
        so fact = fact * i =20 * 3 = 60
        then i = i-1 =3 -1 = 2 
        so we get here two value fist one is fact = 60 and i= 2 .
        
     CASE 4 :- (2 > 0)  is true so it will go through the loop
        so fact = fact * i = 60 * 2 = 120 
        then i = i-1 = 2 - 1 = 1
        so we get here two value fist one is fact = 120 and i= 1.      
 
     CASE 5 :- (1 > 0)  is true so it will go through the loop
        so fact = fact * i = 120 * 1 = 120 
        then i = i-1 = 1 - 1 = 0
        so we get here two value fist one is fact = 120 and i= 1.   
        
     CASE 6 :- (0 > 0 ) is false . So loop will not be called and we come out of the loop 
     
 
 After coming out of the loop we get the value of fact which is equal to 120
 
 So it will print "  The Value is 120 " 

'''


