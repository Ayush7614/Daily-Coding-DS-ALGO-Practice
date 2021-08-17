

//Given an m x n matrix, return all elements of the matrix in spiral order.


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int top=0;
        int down=row-1;
        int left=0;
        int right=col-1;
        int dia=0;
        vector<int> ans;
        
        
        while(top<=down && left<=right)
        {
        
            if(dia==0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            
           else if(dia==1)
            {
                for(int i=top;i<=down;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            
            if(dia==2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            
            if(dia==3)
            {
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
          dia=(dia+1)%4;  
        }
       return ans;
    }
};

