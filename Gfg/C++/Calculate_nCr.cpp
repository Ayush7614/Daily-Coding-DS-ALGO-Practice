
//C++ Solution of Calculate nCr
#include<bits/stdc++.h> 
using namespace std; 

//Finding minimum
int min(int number1,int number2)
{
	return (number1<number2? number1:number2);
}
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
  
	int testCases;
	cin>>testCases;
	//Total test Cases
	while(testCases-->0)
	{
		int n,r;
		cin>>n>>r;
		unsigned long int c[r+1]={0};
		c[0]=1;
		//Using mathematical formula C(n,r)=n!(r!(n−r)!) 
		for(int i=1;i<=n;i++)
			for(int j=min(i,r);j>0;j--) 
				c[j]+=c[j-1]%1000000007;

		//If value is very large perfomed modulus
		cout<<c[r]%1000000007<<endl;
	}
	
		return 0; 
} 

/*
Input
2
3 2

Output
3
0

Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800

Complexity Analysis
Time Complexity: O(n*r)
Auxiliary Space: O(r)


*/