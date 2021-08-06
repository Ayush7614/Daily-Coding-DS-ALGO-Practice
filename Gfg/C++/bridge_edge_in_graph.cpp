// Link to problem:
//https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
    
    void dfs( vector<int> adj[],vector<int>&v,int i)
    {
        v[i]=1; //marking visited
        
        for(auto x:adj[i]) //traversing adjacent node
        {
            if(!v[x])
                dfs(adj,v,x);
            
        }
           
    }
    
    bool connected(vector<int>adj[],int n,int c,int d)
    {
        vector<int>v(n,0);
        
        dfs(adj,v,c); // dfs from edge c
        
        if(v[d]==0) //if edge d is not visited means not connected
            return false;
            
        return true;
        
    }
  
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int>adj[], int c, int d) 
    {
        if(!connected(adj,n,c,d)) //if graph is not connected
            return 0;
            
        else
        {
            //removing edge c and d
            adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
            adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
            
            
            if(connected(adj,n,c,d)) //if connected means no bridge
                return 0;
            else
                return 1;
        }
    
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

// Time Complexity : O(N)
// Space Complexity : O(N)
/*
Input:
t=1
V=4 E=3
0 1
1 2
2 3
c=1  d=2

Output: 1
  */