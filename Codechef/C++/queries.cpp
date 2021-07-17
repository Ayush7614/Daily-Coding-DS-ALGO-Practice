/*Link to the problem-
https://www.codechef.com/START5C/problems/CHEFQUER/
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,q;
	cin>>n>>q;
	vector<long long>arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	while(q--)
	{
	    long long num;
	    cin>>num;
	    if(num==1)
	    {
	        long long l,r,x;
	        cin>>l>>r>>x;
	        for(int i=l-1;i<=r-1;i++)
	        {
	            arr[i]=arr[i]+((x+i+1-l)*(x+i+1-l));
	        }
	    }
	    if(num==2)
	    {
	        long long y;
	        cin>>y;
	        cout<<arr[y-1]<<endl;
	    }
	}
	return 0;
}

/*
Input-
5 4
1 10 3 6 5
1 1 3 5
2 3
1 4 5 7
2 5
Output-
52
69
*/

