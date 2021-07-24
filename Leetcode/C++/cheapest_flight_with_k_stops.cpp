//Link to problem: 
//https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>g(n);
        
        for(auto x:flights)
        {
            g[x[0]].push_back(make_pair(x[1],x[2]));
        }        
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<int>dist(n+1, INT_MAX);
        
        pq.push(make_tuple(0,src,0));
        
        while(!pq.empty())
        {
            auto [cost,s,stop]=pq.top();
            pq.pop();
            
            if(dist[s]< stop) continue; 
		    dist[s]= stop;
            
            if(s==dst)
                return cost;
            if(stop>k)
                continue;
            
            for(auto x:g[s])
            {
                auto [u,v]=x;
                
                pq.push(make_tuple(cost+v,u,stop+1));
            }
            
        }
        
        return -1;
        
    
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--)
    {
		vector<vector<int>>flights;
		int V,E;
		cin >> V>>E;

        for(int i=0;i<E;i++)
        {
            int s,e,cost;
            cin>>s>>e>>cost;
            vector<int>v;
            v.push_back(s);
            v.push_back(e);
            v.push_back(cost);
            flights.push_back(v);
        }

        int src,dst,k;
        cin>>src>>dst>>k;

		Solution obj;
		int ans = obj.findCheapestPrice(V,flights,src,dst,k);
		cout << ans <<"\n";
	}
	return 0;
}  

/*

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
*/