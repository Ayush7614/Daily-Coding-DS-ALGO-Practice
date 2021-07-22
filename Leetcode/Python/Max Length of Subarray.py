"""
Solution Authored by : zualemo
Question Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/


Given two integer arrays nums1 and nums2, return the maximum
length of a subarray that appears in both arrays.

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
"""

class Solution(object):
    def findLength(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        #create 2d array for dp
        l=[[0 for i in range(0,len(nums1))] for j in range(0,len(nums2))]
        #print(l)
        
        #to find the max length
        maxn=0
        
        #traverse through the dp elements
        for i in range(0,len(nums2)):
            for j in range(0,len(nums1)):
                if(i==0 and nums1[j]==nums2[i]):
                    l[i][j]=1

                #add value of the i-1,j-1 th element as they form a subarray    
                elif((j!=0 and i!=0) and nums1[j]==nums2[i]):
                    l[i][j]=1+l[i-1][j-1]
                    
                    if(l[i][j]>maxn):
                        maxn=l[i][j]
                        
                elif(j==0 and nums1[j]==nums2[i]):
                    l[i][j]=1
                    if(l[i][j]>maxn):
                        maxn=1
        #print(l)
        return(maxn)
