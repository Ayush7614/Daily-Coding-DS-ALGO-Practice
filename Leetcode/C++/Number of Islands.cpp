// question
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3



class Solution {
public:
    void mark(vector<vector<char>>& grid,int x,int y,int rows,int cols){
        if(x<0 || x>=rows|| y<0|| y>=cols || grid[x][y]!='1'){
            return;
    }
        grid[x][y]='2';
     
        mark(grid,x+1,y,rows,cols);//down
        mark(grid,x,y+1,rows,cols);//right
        mark(grid,x-1,y,rows,cols);//top
        mark(grid,x,y-1,rows,cols);//left
    }
        int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows== 0) return 0;
        int cols=grid[0].size();
        int no_of_island = 0;
        for(int i =0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j]=='1'){
                    mark(grid,i,j,rows,cols);
                    no_of_island += 1;
                }
            }
        }
        return no_of_island;
    }
};
