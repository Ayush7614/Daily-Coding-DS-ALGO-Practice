  //C++ solution of Handshakes problem
 /*
Problem Statement:
We have N persons sitting on a round table. Any pers
on can do a handshake with any other person.

     1
2         3
     4

Handshake with 2-3 and 1-4 will cause cross.
In how many ways these N people can make handshakes 
so that no two handshakes cross each other. N would be even. 

Approach:
Recursive solution:
Consider a circle with n points on circumference 
of it where n is even. Count number of ways we can 
connect these points such that no two connecting lines 
to cross each other and every point is connected with 
exactly one other point. Any point can be connected with any other point.
 
We considered base case first two check if total persons are 0 
if it is then returned 1 ,
if not then we go for counting number of ways
    We need to connect n points such that there is no crossing lines between 
    them. When we connect two points, we divide the points in two sets that 
    needs be to connected. Each set needs to be connected within itself,this same
    recurrence relation is used here. finally we returned the number of ways.
*/
#include<bits/stdc++.h> 
using namespace std; 
class Solution
   {
   public:
int handShake(int totalPersons)
{
    if(totalPersons==0)
    {
    	return 1;
    }
    else
    {
        int ways=0;
        for(int i=2;i<=totalPersons;i+=2)
        {
            ways+=handShake(i-2)*handShake(totalPersons-i);
        }
        return ways;
    }
}

   	
   };

   int main() 
   { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   cout.tie(NULL);
 
   int testCases;
   cin>>testCases; 
   while(testCases-->0) 
   { 

  Solution obj;
   int totalPersons;
   cin>>totalPersons;
      cout<<obj.handShake(totalPersons)<<endl; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
 } 

/*
Input:
5
2
4
0
17
6

Output:
1
2
1
0
5


Complexity Analysis:
Time Complexity: O(2^n)
Space Complexity: O(1)
 
Constraints:
1 <= n <= 30

*/