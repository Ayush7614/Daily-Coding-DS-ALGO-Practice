// Link tp problem:
//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

/*Algorithm:
First we will push the index of grid having value 2(rotten orange) and count total no of fresh oranges. Then we will keep poping 
index from queue and add the adjacent oranges which will get rot. We will keep count of answer and after the queue become empty 
we will check that if there is no fresh oranges left we will return the ans else -1(not possible to rot all oranges)

*/

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),i,j,t=0,f=0;
        queue<pair<int,int>>q;
        
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j}); //stoding in queue
                else
                {
                    if(grid[i][j]==1)
                        f++; //keeping fresh count
                }
            }
            
        
        
        while(!q.empty())
        {
            int m=q.size();
            for(i=0;i<m;i++)
            {
                int x=q.front().first,y=q.front().second;
                
                q.pop();
                
                //Checking adjacent fresh oranges
                if(x>0 && grid[x-1][y]==1)
                {
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    f--;
                }
                if(x<r-1 && grid[x+1][y]==1)
                {
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    f--;
                    
                }
                 if(y>0 && grid[x][y-1]==1)
                {
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    f--;
                    
                }
                 if(y<c-1 && grid[x][y+1]==1)
                {
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    f--;
                    
                }
                
            }
            if(!q.empty()) // There is chance to rot more oranges
                t++;
            
        }
        
         return (f==0)?t:-1;
        
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

/*
Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).


*/