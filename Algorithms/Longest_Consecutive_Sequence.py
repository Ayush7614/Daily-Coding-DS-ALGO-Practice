
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
print(Solution().longestConsecutive({13,15,19,16,21,17,18,23,1,4})) #Calling two function Solution and longestConsecutive
