//Maximum Index Solution in C++

/*
Problem Stament:
Given an array A[] of N positive integers. 
The task is to find the maximum of j - i subjected 
to the constraint of A[i] <= A[j].

Approach:
Run two loops. In the outer loop, 
pick elements one by one from the left. 
In the inner loop, compare the picked 
element with the elements starting from 
the right side. Stop the inner loop when
 you see an element greater than the 
 picked element and keep updating the maximum j-i so far. 
*/

#include<bits/stdc++.h> 
using namespace std; 
class Solution
{
public:
int maxIndex(int arr[], int size)
{
    int maxDiff = -1;
    int i, j;

    for (i = 0; i < size; ++i) 
    {
        for (j = size - 1; j > i; --j) {
            if (arr[j] > arr[i] && maxDiff < (j - i))
                maxDiff = j - i;
        }
    }

    return maxDiff;
}
    
};
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
   cin>>testCases; 
   while(testCases-->0) 
   { 
     int size;
     cin>>size;
     int arr[size];
     for (int i = 0; i < size; ++i)
        cin>>arr[i];

      Solution obj;

      cout<<obj.maxIndex(arr,size)<<endl; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
   } 

/*
Input:
3
2
1 10
9
34 8 10 3 2 80 30 33 1
5
3 43 5 44 2
Output:
1
6
3


Complexity Analysis:
Time Complexity: O(n^2)
Space Complexity: O(n)

Constraints:
1 ≤ N ≤ 10^7
0 ≤ ARR[i] ≤ 10^18
*/