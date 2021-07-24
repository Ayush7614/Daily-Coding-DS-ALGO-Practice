
//C++ Solution of Calculate nPr 
/*
Approach :
First calculated factorial of n and (n-r) to solve
it using this formula nPr = n!/(n-r)! 
*/

#include<bits/stdc++.h> 
#define ll long long int
using namespace std; 

//Calculating Factorial recursive approach 
ll fact(ll n)
{
    if(n<2)
    {
        return 1;

    }
    else
    {
        return n*fact(n-1);
    }

}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
   
    int testCases;
    cin>>testCases;
    while(testCases-->0)
    {
        ll n,r;
        cin>>n>>r;
       //n! means we need to calculate factorial
       //Printing final answer
        cout<<fact(n)/fact(n-r)<<endl;
    }

    return 0; 
} 

/*
Input
3
2 1
3 5
3 3

Output
2
6
6

Complexity Analysis
Time Complexity: O(n)
Auxiliary Space: O(1)

Constraints:
1 ≤ n, r ≤ 20

*/



