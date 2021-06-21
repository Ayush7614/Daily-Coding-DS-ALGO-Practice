class Solution(object): #main function
   def longestConsecutive(self, values): #sub funcction
      longest_consecutive_series = 0 # Initializing
      for i in values:  # Iteration the given value
         if i-1 not in values:  # condition check
            value = i
            count_of_consecutive_numbers = 0
            while i in values:
               i+=1
               count_of_consecutive_numbers+=1
               longest_consecutive_series = max(longest_consecutive_series,count_of_consecutive_numbers) #maximum finding
      return longest_consecutive_series
print(Solution().longestConsecutive({13,15,19,16,21,17,18,23,1,4})) #Calling two function Solution and longestConsecutive
