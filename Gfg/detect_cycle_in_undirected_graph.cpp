#include<bits/stdc++.h>
using namespace std;
class Solution 
{
   public:
    bool bfscycle(int s,int V, vector<int>adj[],vector<int>&visited  )
    {
        vector<int> parent(V, -1);
        queue<pair<int,int>>q;
        visited[s]=true;
        q.push({s,-1});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int pre=q.front().second;
            q.pop();
            for(auto it : adj[node])
            {   
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(pre!=it)
                {
                    return true;
                }
            }
           
        }
         return false;
    }
    //Function to detect cycle in an undirected graph.
    public:
    bool isCycle(int V, vector<int>adj[])
	{
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(bfscycle(i,V,adj,vis)) return true;
	        }
	          
	    }
	     return false;
	}	
};
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int V,E;
        cin>>V>>E;
        vector<int>adj[V];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
        Solution obj;
        bool ans=obj.isCycle(V,adj);
        if(ans)
        {
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
       
    }
 return 0;
}
/*Input  :-
1->2->3->4->1
Output : 1

Input : 0 1->2->3
Output: 0*/
