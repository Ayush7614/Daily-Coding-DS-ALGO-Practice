// Link to problem:
//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

/*Algorithm: 
We will use DFS traversal. During traversal if a node is already visited and its not equal to its parent value means 
there exist a cycle so we will return true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    bool checkCycle(int i,int p,vector<int>adj[],vector<bool>&v)
    {
      
        v[i]=true; //marking visited
        for(auto x:adj[i]) // traversing adjacent nodes
        {
            if(!v[x])
            {
                if(checkCycle(x,i,adj,v)) // cycle exist
                    return true;
                
            }
            else
                if(x!=p) // node is not equal to parent
                    return true;
                
            
        }
        return false;
    }

    //Function to detect cycle in an undirected graph.
	bool isCycle(int n, vector<int>adj[])
	{
	    vector<bool>v(n,false);
	    for(int i=0;i<n;i++)
	    {
	        if(!v[i]) //not visited
	        {
	            bool f=checkCycle(i,-1,adj,v);
	            if(f)
	                return true;
	        }
	    }
	    return false;
	}
};


int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  

/*

Input:
V=4  N=2
1 2
2 3 

Output: 0
Explanation: No cycle in the graph.

*/