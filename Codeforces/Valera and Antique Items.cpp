#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
    
	int n, v;
	cin>>n>>v;
	vector<int> ans;
	loop(i,0,n)
	{
		bool u=false;
		int k,s;
		cin>>k;

		loop(j,0,k)
		{
			cin >> s;
			if (!u && v>s)
			{
				u=true;
				ans.push_back(i);
			}
		}
	}

	cout << ans.size() << endl;
	loop(i,0,ans.size())
		cout << ans[i]+1 << " ";
	
	
	    return 0;
}