//Link to solution:
//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

/*Algorithm:
 We will use DFS and check all 8 adjacent grid block. Number of times DFS will be called is equal to number of islands.
 */


#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    
    void dfs(int i,int j,vector<vector<char>>grid,int v[501][501],int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return;
            
        if(int(grid[i][j]-'0')==0)
            return;
             
        if(!v[i][j]) // checking all 8 adjacent block
        {
            v[i][j]=1;  //marking visited
            dfs(i+1,j,grid,v,m,n);
            dfs(i-1,j,grid,v,m,n);
            dfs(i,j+1,grid,v,m,n);
            dfs(i,j-1,grid,v,m,n);
            dfs(i+1,j+1,grid,v,m,n);
            dfs(i-1,j-1,grid,v,m,n);
            dfs(i+1,j-1,grid,v,m,n);
            dfs(i-1,j+1,grid,v,m,n);
            
        }
        
        
    }
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int i,j;
        int m=grid.size(),n=grid[0].size();
        
        int v[501][501];
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                v[i][j]=0; //marking unvisited
          
        int ans=0;      
         for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(!v[i][j] && int(grid[i][j]='0')==1)
                {
                    ans++;
                    dfs(i,j,grid,v,m,n);
                    
                }
                
            }
            
            return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends

/*
Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
*/