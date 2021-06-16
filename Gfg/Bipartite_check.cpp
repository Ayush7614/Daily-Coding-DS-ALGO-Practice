

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool bipartitebfs(int s,vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(s);
    color[s]=1;
       // Run while there are vertices 
    // in queue (Similar to BFS)
    while(!q.empty())
    {
        //here we will simple write the element which will be on the top of the queue.
        int node=q.front();
        //than pop it.
        q.pop();
        //here we will iterate all elements which will be in the color array.
        for(auto it: adj[node])
        {
            //An edge from u to v exists and 
            // destination v is not colored
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            //Assign alternate color to this adjacent v of u
                
            else if(color[node]==color[it])
            {
                return false;
            }
        }
    }
    // If we reach here, then all adjacent  
    // vertices can be colored with alternate color
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
        //set the whole color array to -1 
	    memset(color,-1,sizeof color);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
                //calling for bipartite
	            if(!bipartitebfs(i,adj,color))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	    
	}

};

//  Driver Code Starts.
int main(){
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends

//Input 
// 0, 1, 0, 1
// 1, 0, 1, 0
// 0, 1, 0, 1
// 1, 0, 1, 0
//Output
//Yes