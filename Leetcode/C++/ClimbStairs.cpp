/*
Problem: Climbing Stairs on LeetCode, solution by AtrikGit6174
Both recursive and iterative solns are there. Please read the comments in the functions.
Both methods effectively use memoisation: storing values for subproblems for optimising 
against re-calculation of previously encouuntered subproblems to finally solve the problem.

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
-- 1 <= n <= 45
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
    
    vector <int> vec;   //for iterative approach
    map <int,int> mp;   //for recursive approach. stairs:no. of ways pairs.
    
public:
    int climbStairs_ite(int n) 
    {
        if (n==1 or n==2)
            return n;
        
        //storing base cases.
        vec.push_back (1);
        vec.push_back (2);
        
        //iterative approach
        for (int i=2; i<n; i++)
            vec.push_back (vec[i-2]+vec[i-1]);
        
        return vec[n-1];
        
    }
    
    int climbStairs_rec(int n) 
    {
        if (n==1 or n==2)
            return n;
        
        //storing base cases.
        mp.insert(make_pair(1,1));
        mp.insert(make_pair(2,2));
        
        //recursive approach
        if (mp.find(n)==mp.end())
            //notice that climbStairs_rec (n-2) is called before climbStairs (n-1)
            //as value for n-1 relies on value for n-2
            mp.insert(make_pair(n,climbStairs_rec(n-2)+climbStairs_rec(n-1)));  
        
        return mp[n];
        
    }
};

int main() 
{
   cout<<"Enter the number of stairs [1-45]: ";
   int n; cin>>n;
   
   Solution ob;
   cout<<"\nNo. of ways\n1. Iterative: "<<ob.climbStairs_ite(n)<<"\n2. Recursive: "<<ob.climbStairs_rec(n);
   return 0;
   
}
