
# lcs = longest_consecutive_series
# ccn = count_of_consecutive_numbers
class Solution(object): #main function
   def longestConsecutive(self, values): #sub funcction
      lcs = 0 # Initializing
      for i in values:  # Iteration the given value
         if i-1 not in values:  # condition check
            value = i
            ccn = 0
            while i in values:
               i+=1  #increament
               ccn+=1  #increment
               lcs = max(lcs,ccn) #maximum finding
      return lcs
print(" Length of LCS is ",Solution().longestConsecutive({13,15,19,16,21,17,18,23,1,4})) #Calling two function Solution and longestConsecutive
 
'''   
   longestConsecutive will be called and it will pass the value.
   longest_consecutive_series value will be assign
   
   loop will be called 
   for i = 1 (True ):- 
                        if i-1 not in values ( True ):-
                        value =  1
                        count_of_consecutive_numbers = 0 
                        for i =1 (True )
                            i +=1  , i=2
                            count_of_consecutive_numbers = 1
                            max will be find between longest_consecutive_series,count_of_consecutive_numbers

                        for i =2 ( False )
                            back to main loop. 
  
  for i = 4 ( True ) :-  
                          if i-1 not in values ( True ):-
                          value = 4
                          count_of_consecutive_numbers = 0 
                          for i = 4 (True )
                              i +=1  , i = 5
                              count_of_consecutive_numbers = 1
                              longest_consecutive_series =1

                         
                         for i = 5 ( False )
                             back to main loop
                         
for i = 5 (False ) :-   The value of i will be iterate

for i = 13 (True ) :-   
                        if i-1 not in values ( True ):-
                        value =  13 
                        count_of_consecutive_numbers = 0 
                        for i = 13 ( True )
                              i +=1  , i = 13
                              count_of_consecutive_numbers = 1
                              longest_consecutive_series =


                         for i = 14 (False)
                              back to main loop
                              
 for i = 14 (False ):- 
                        if i-1 not in values ( False )                       
 
 for i = 15 (True ):-  
                       if i-1 not in values ( True ):-
                       value =  15
                       count_of_consecutive_numbers = 0 
                       for i = 15 ( True )
                            i +=1  , i = 16
                            count_of_consecutive_numbers = 1
                             longest_consecutive_series =1


                       for i = 16 ( True )
                            i +=1  , i = 17
                            count_of_consecutive_numbers = 2
                             longest_consecutive_series =2

                              
                       for i = 17 ( True )
                            i +=1  , i = 18
                            count_of_consecutive_numbers = 3
                            longest_consecutive_series =3
      

                       for i = 18 ( True )
                            i +=1  , i = 19
                            count_of_consecutive_numbers = 4
                            longest_consecutive_series =4
     

                       for i = 19 ( True )
                            i +=1  , i = 20
                            count_of_consecutive_numbers = 5
                            longest_consecutive_series =5

                       for i = 20 ( False )
                           back to main loop

for i = 16 ( True ):- 
                        if i-1 not in values ( False ):-
                              back to main loop


for i = 17 ( True ):-
                        if i-1 not in values ( False ):-
                              back to main loop
                                                           
for i = 18 ( True ):-
                        if i-1 not in values ( False ):-
                              back to main loo

for i = 19 ( True ):-
                        if i-1 not in values ( False ):-
                              back to main loo


for i = 21 ( True ):- 
                        if i-1 not in values ( True ):-
                        value =  21
                        count_of_consecutive_numbers = 0 
                        for i = 21 ( True )
                            i +=1  , i = 22
                            count_of_consecutive_numbers = 1
                            longest_consecutive_series =1

                     
                        for i = 22 ( False ):-
                                 back to main loop

for i = 23 ( True ):-
                       if i-1 not in values ( True ):-
                       value =  23
                       count_of_consecutive_numbers = 0 
                        for i = 23 ( True )
                            i +=1  , i = 24
                            count_of_consecutive_numbers = 1
                            longest_consecutive_series = 1

                        for i = 24 (False ):-
                             back to main loop
'''










