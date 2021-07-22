
/*

This is code forces level B question.
Question code is 160 B.


test case 1:
## input :
2
2421
## output :
YES

test case 2:
## input :
2
3754
## output :
NO


*/

//79 Unlucky Ticket
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(true);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long int a[101],a1[101];
	long long int n;
	cin>>n;
	string s;
	cin>>s;
	string s1 = s.substr(0,n);
	sort(s1.begin(),s1.end());
	string s2 = s.substr(n,n);
	sort(s2.begin(),s2.end());
	//cout<<s1<<"\n"<<s2<<endl;
	s = s1+s2;
	//cout<<s<<endl;
	memset(a,-1,sizeof(a));
	memset(a1,-1,sizeof(a1));
	bool flag2 = true;
	for(int i=0;i<n;i++)// strictly less case, first half < second half
	{
		//cout<<"i = "<<i<<endl;
		bool flag1 = false;
		for(int j=n;j<2*n;j++)
		{
//			cout<<"j = "<<j<<endl;
//			cout<<s[i]<<" "<<s[j]<<" "<<a[j-n]<<endl;
			if(s[i]<s[j] && a[j-n]==-1)
			{
				//cout<<"hey\n";
				flag1 = true;
				a[j-n]=0;
//				for(int k=0;k<n;k++)
//				{
//					cout<<a[k]<<" ";
//				}
//				cout<<endl;
				break;
			}
		}
		//cout<<"flag1 = "<<flag1<<endl;
		if(!flag1)
		{
			flag2 = flag1;
			break;
		}
	}
	//cout<<"flag2 = "<<flag2<<endl;
	if(!flag2)
	{
		//cout<<"if\n";
		bool flag4 = true;
		for(int i=0;i<n;i++)// strictly less case, first half < second half
		{
			//cout<<"i = "<<i<<endl;
			bool flag3 = false;
			for(int j=n;j<2*n;j++)
			{
//				cout<<"j = "<<j<<endl;
//				cout<<s[i]<<" "<<s[j]<<" "<<a1[j-n]<<endl;
				if(s[i]>s[j] && a1[j-n]==-1)
				{
					//cout<<"hey1\n";
					flag3 = true;
					a1[j-n]=0;
//					for(int k=0;k<n;k++)
//					{
//						cout<<a1[k]<<" ";
//					}
//					cout<<endl;
					break;
				}
			}
			//cout<<"flag3 = "<<flag3<<endl;
			if(!flag3)
			{
				flag4 = flag3;
				break;
			}
		}
		//cout<<"flag4 = "<<flag4<<endl;
		if(!flag4)
		cout<<"NO";
		else
		cout<<"YES";
	}
	else
	cout<<"YES";
    return 0;
}
