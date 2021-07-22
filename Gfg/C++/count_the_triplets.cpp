//C++ Solution of Count the triplets

/*
Problem statement
Given an array of distinct integers. The task is to count 
all the triplets 
such that sum of two elements equals the third element.

Approach:
Sort the given array first then linearly traversed,
to check sum we need at least two elements so used 'k' as 
as next (third) index to check sum with kth index element,
array is already sorted previously so now we only need to check sum 
is sum equals to third element or less 
if sum is less than kth element (i.e. third element which we have to check)
then incresment jth index till sum is less
if sum if equal or greater it will be out loop and check if sum is 
equal increment count and j 
repeat until and elements are traversed

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:	
   //Function to count triplets 
   int countTriplet(int arr[], int size)
	{
        //sorted using sort() complexity O(n)
        sort(arr,arr+size);
        //to store count of triplets
        int count=0;
        
        for(int i=0;i<size;++i)
        {
            int j=i+1;
            int k=j+1;
            while(k<size)
            {
                //base case
                if(arr[i]+arr[j]<arr[k])
                {
                    while(arr[i]+arr[j]<arr[k]) 
                          j++;
                }
             if(arr[i]+arr[j]==arr[k])
                {
                    count++;
                    j++;
                }
                k++;
            }
            
        }
      
       if(count==0) 
          return 0;
       else 
          return count;
    
  
  	}
};

//Driver code
int main() 
{
   	
  ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   cout.tie(NULL);
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 

   	int testCases;
    cin >> testCases;
    while (testCases-->0)
    {
        int size;
        cin >> size;

        int arr[size];
        for(int i = 0; i < size; i++)
        	cin >> arr[i];

        Solution obj;
        cout << obj.countTriplet(arr, size) <<endl;

    }

    return 0;
} 

/*
Input:
3
4
1 5 3 2
3
2 3 4
7
2 1 45 56 6 23 5

Output:

Time Complexity:
Time Complexity: O(N^2)
Auxiliary Space: O(1)

*/
