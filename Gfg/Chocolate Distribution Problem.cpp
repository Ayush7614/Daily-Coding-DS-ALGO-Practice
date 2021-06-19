
// C++ solution of chocolate distribution problem

/*
Problem Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1 
*/

/* 
Input : n=7, m=3, arr[] = {7, 3, 2, 4, 9, 12, 56}
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and 
we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum 
difference between maximum and minimum packet 
sizes.
*/

#include <bits/stdc++.h>
using namespace std; 

long long findMinDiff(long long a[], long long n, long long m)
    {
        long long i,ma=INT_MAX;
        
        // if there are no chocolates or number of students is 0
        if (m==0 || n==0)
        return 0;
        
        // Number of students cannot be more than number of packets
        if (n < m)
        return -1;
 
        // Sorting the given packets
        sort(a,a+n);
        
        // Iterating through the sorted array to find the subarray of size m such that              difference between last and first elements of subarray is minimum.
        for(i=0;i<n-m+1;i++)
        {
            ma=min(ma, a[i+m-1]-a[i]);
        }
        
        return ma;
    }  
  
int main()
{
    long long n,m;
    cin>>n>>m;  //taling no. of packets & no.of students as input
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    
    cout << "Minimum difference is: "<< findMinDiff(a, n, m);
    return 0;
}