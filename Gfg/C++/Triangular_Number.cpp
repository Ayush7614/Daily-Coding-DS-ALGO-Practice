//C++ Solution of Triangular Number
/*
Problem statement:
Given a number n,Check whether it is a triangular number or not.
Approach Bruteforce:
   A number is termed as a triangular number if we can represent 
it in the form of a triangular grid of points such that the 
points form an equilateral triangle and each row contains 
as many points as the row number, i.e., the first row has one point, 
the second row has two points, the third row has three points and so on.
The starting triangular numbers are 1, 3 (1+2), 6 (1+2+3), 10 (1+2+3+4).

we started with 1 and added it to the final sum upto the final sum is 
less than the number given finally we checked if the resultant sum is 
equal to the number provided if it is then returned 1 otherwise returned 0.
*/
#include<bits/stdc++.h> 
using namespace std; 
class Solution
{
public:
 int isTriangular(int number)
 {
   int result_sum=0;
   for(int i=1;result_sum<number;i++)
       result_sum=result_sum+i;

   if(result_sum==number)
     return 1;
   else
     return 0;
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
    Solution obj;
    int n;
    cin>>n;
    cout<<obj.isTriangular(n);
    cout<<endl; 
} 

cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
} 

/*
Input:
5
55
12
91
101
8128

Output:
1
0
1
0
1

Constraints:
1<=testCases<=100
1<=n<=10^6

*/