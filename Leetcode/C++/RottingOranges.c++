class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int time) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || 1 < grid[i][j] && grid[i][j]<time)
            return; 
        grid[i][j]=time;
        dfs(grid,i-1,j,grid[i][j]+1);
        dfs(grid,i+1,j,grid[i][j]+1);
        dfs(grid,i,j-1,grid[i][j]+1);
        dfs(grid,i,j+1,grid[i][j]+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
         for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) dfs(grid, i, j,grid[i][j]); 
            }
        }
        int totalTime=2;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==1) 
                    return -1;
                totalTime=max(grid[i][j],totalTime);
            }
            cout<<endl;
        }
        return totalTime-2;
    }
};
