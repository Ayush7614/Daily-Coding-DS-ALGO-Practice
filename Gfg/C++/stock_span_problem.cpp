#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int>v;
       stack<pair<int,int>>s;
       for(int i=0;i<n;i++){
           if(s.size()==0){
               v.push_back(-1);
           }
           else if(s.size()>0 && s.top().first>price[i]){
               v.push_back(s.top().second);
           }
           else if(s.size()>0 && s.top().first<=price[i]){
               while(s.size()>0 && s.top().first<=price[i]){
                   s.pop();
               }

          if(s.size()==0){
              v.push_back(-1);
          }
           else{
               v.push_back(s.top().second);
           }
           }
           s.push({price[i],i});
       }
       for(int i=0;i<v.size();i++){
           v[i]=i-v[i];
       }
       return v;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}

     Solution obj;
    vector<int>s=obj.calculateSpan(a,n);
    for(int i=0;i<n;i++){
          cout<<s[i]<<" ";

    }

   cout<<endl;    
}
    return 0;
}
