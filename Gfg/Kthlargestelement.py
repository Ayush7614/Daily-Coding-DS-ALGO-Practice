class Solution(object):
   def findKthLargest(self, nums, k):
      nums.sort()
      if k ==1:
         return nums[-1]
      temp = 1
      return nums[len(nums)-k]
obj1 = Solution()
n=int(input("size "));
a=[]
for i in range(0,n):
  ele=int(input("Enter array elements "))
  a.append(ele)
k=int(input())
print(obj1.findKthLargest(a,k))