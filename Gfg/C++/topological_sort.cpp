//Link to problem :
//https://practice.geeksforgeeks.org/problems/topological-sort/1

/*Algorithm: 
We will use stack for storing result during dfs traversal because if there is an edge between 1->2 
then we want 1 to come before 2 in order to get Topological Sorting of that Graph.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	
	void dfs(vector<int> adj[],int i,vector<int>&v,stack<int>&s) //dfs traversal
	{
	    v[i]=1;
	    
	    for(auto x:adj[i])
	    {
	        if(!v[x])
	            dfs(adj,x,v,s);
	    }
	    
	    s.push(i); //pushing to stack
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    stack<int>s;
	    vector<int>v(n,0);
	    vector<int> ans;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(!v[i])
	            dfs(adj,i,v,s);
	        
	    }
	    
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends

/*
Input :
V=4  E=3

1->0
2->0
3->0

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.

*/

