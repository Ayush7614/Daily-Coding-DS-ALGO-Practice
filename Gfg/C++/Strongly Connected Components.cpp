//Link to problem:
//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

/*Algorithm:
We will follow 3 steps:
1. Sort all nodes in order of finishing time (Topo Sort)
2. Transpose the graph
3. DFS according to transposed graph

The numder of times our final dfs will be called is the number of Strongly Connected Components.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	void dfs(vector<int> adj[],int i,vector<int>&v, stack<int>&s) // Topo sort of graph
	{
	    v[i]=1;
	    
	    for(auto x:adj[i])
	    {
	        if(!v[x])
	            dfs(adj,x,v,s);
	    }
	    
	    s.push(i);
	    
	}
	void rdfs(int i,vector<int>trans[],vector<int>&v) //DFS of transposed graph
	{
	    v[i]=1;
	    
	    for(auto x:trans[i])
	    {
	        if(!v[x])
	            rdfs(x,trans,v);
	    }
	    
	}
	
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int>s;
        vector<int>v(n,0);
        int i;
        
        for(i=0;i<n;i++)
        {
            if(!v[i])
                dfs(adj,i,v,s);
        }
        
        vector<int>trans[n];
        
        for(i=0;i<n;i++) // Transposing the graph
        {
            v[i]=0;
            for(auto x:adj[i])
                trans[x].push_back(i);
            
        }
        
        int ans=0;
        while(!s.empty())
        {
            int t=s.top();
            s.pop();
            if(!v[t])
            {
                ans++;
                rdfs(t,trans,v);
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

  /*
  Input:
  V=5 E=5
  
  0,2
  0,3
  1,2
  2,1
  3,4

  Output: 3

  */