
/*

This is c++ code for Rank List Ques of codefoerces
Ques tag - 166_A 

*/


#include<bits/stdc++.h>
using namespace std;
bool sortbyfirst(const pair<long long int , pair<long long int , long long int > > &a, const pair<long long int , pair<long long int , long long int > > &b) 
{ 
    return (a.first > b.first); 
}
bool sortbysecfirst(const pair<long long int , pair<long long int , long long int > > &a, const pair<long long int , pair<long long int , long long int > > &b) 
{ 
    return (a.second.first < b.second.first); 
}
int main()
{
	ios::sync_with_stdio(true);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long int n,k;
	cin>>n>>k;
	map< pair<long long int, long long int > , long long int > mp;
	vector< pair<long long int , pair<long long int , long long int > > > v;
	vector< pair<long long int , pair<long long int , long long int > > > v1[51];
	for(int i=0;i<n;i++)
	{
		long long int p,t;
		cin>>p>>t;
		mp[{p,t}]++;
		v.push_back(make_pair(p,make_pair(t,i+1)));
	}
	sort(v.begin(),v.end(),sortbyfirst);
//	cout<<endl<<"After sorted by 1st "<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
//	}
	long long int sz = 0;
	v1[sz].push_back(make_pair(v[0].first,make_pair(v[0].second.first,v[0].second.second)));
	//cout<<v[0].first<<" "<<v[0].second.first<<" "<<v[0].second.second<<endl;
	for(int i=1;i<n;i++)
	{
		//cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
		if(v[i].first == v[i-1].first)
		{
			//cout<<"i = "<<i<<endl;
			v1[sz].push_back(make_pair(v[i].first,make_pair(v[i].second.first,v[i].second.second)));
		}
		else
		{
			//cout<<"i = "<<i<<endl;
			sort(v1[sz].begin(),v1[sz].end(),sortbysecfirst);
			sz++;
			v1[sz].push_back(make_pair(v[i].first,make_pair(v[i].second.first,v[i].second.second)));
		}
	}
	sort(v1[sz].begin(),v1[sz].end(),sortbysecfirst);
	//cout<<endl<<sz<<endl;
	//cout<<endl<<"After sorted by 2nd "<<endl;
	for(int i=0;i<=sz;i++)
	{
		for(int j=0;j<v1[i].size();j++)
		{
			k--;
			if(k==0)
			{
				cout<<mp[{v1[i][j].first,v1[i][j].second.first}];
				return 0;
			}
			//cout<<v1[i][j].first<<" "<<v1[i][j].second.first<<" "<<v1[i][j].second.second<<endl;
		}
	}
    return 0;
}
