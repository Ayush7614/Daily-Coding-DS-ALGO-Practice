// Given a fence with n posts and k colors, find out the number of ways of 
// painting the fence such that at most 2 adjacent posts have the same color.  


#include <iostream>
using namespace std;

int solve(int n, int k)
{
    if(n == 1) return k;
  
    int same = k;                    // same color fences 'ii'
    int diff = k * (k-1);           // different color fences 'ij'
    int total = same + diff;       // total 'ii'+'ij'
    
    for(int i = 3;i <= n;i++){
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }
    return total;
}

int main()
{
    int n,k;
    cout<<"Enter n and k "; // n = no of fences, k = no of colors
    cin>>n>>k;
  
    cout<<"Number of ways of painting the fence with atmost 2 having same color are " <<solve(n,k);
    return 0;
}
