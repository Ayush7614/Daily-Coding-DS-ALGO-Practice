
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution
{   public:
//After the first person (kth from the beginning) is killed, n-1 
// persons are left. So we call josephus(n – 1, k) to get the position with n-1 persons. 
// But the position returned by josephus(n – 1, k) will consider the position starting from
// k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1, k).
int josephus(int n, int k)
    {
        return n==1 ? 1:((k + josephus(n-1, k) - 1)%n + 1);
    }
};
// { Driver Code Starts.
int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends

// Input:
// n = 3 k = 2
// Output: 3
// Explanation: There are 3 persons so 
// skipping 1 person i.e 1st person 2nd 
// person will be killed. Thus the safe 
// position is 3.



// Input:
// n = 5 k = 3
// Output: 4
// Explanation: There are 5 persons so 
// skipping 2 person i.e 3rd person will 
// be killed. Thus the safe position is 4.
