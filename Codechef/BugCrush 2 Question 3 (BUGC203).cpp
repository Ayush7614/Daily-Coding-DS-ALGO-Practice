#include <bits/stdc++.h>
using namespace std;
 int gcd(int x, int y)
{     
    if(x == 0) 					 
   	 return y;
    return gcd(y%x, x);          	 
}
 int  GCD_Helper(vector<int> v, int n)    
{
	int ans = v[0];
	for (int i = 1; i < n; i++)
	{
    	 ans = gcd(v[i], ans);
    	  if(ans==1)
    	    return 1;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v;  
    int input;
	for(int i=0;i<=n;i++)
	{
   	 cin>>input;
   	 v.push_back(input);
    }
    
    
    
	cout << GCD_Helper(v, n) << endl;
	return 0;
}