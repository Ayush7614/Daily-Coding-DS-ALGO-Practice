/*

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.


*/



class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int result=0;
        int cell=0;
        
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==1) {
                    if(i==0||j==0) {
                        result++;
                    }
                    
                    else {
                        cell=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+matrix[i][j];
                        matrix[i][j]=cell;
                        result+=cell;
                    }
                }
            }
        }
        
        return result;
        
    }
};