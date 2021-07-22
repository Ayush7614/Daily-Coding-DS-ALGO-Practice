// UserName- yellowberard

// Given a matrix of size r*c. Traverse the matrix in spiral form.
// link to the Question:- https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

// Input:
// r = 3, c = 4  
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}}
// Output: 
// 1 2 3 4 8 12 11 10 9 5 6 7

// Time Complexity:O(r*c);
// Space Complexity:O(r*c);

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function wriite by yellowberard to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
    
    int row,col,row_start=0,col_start=0,row_end=r-1,col_end=c-1;
     while (row_start<=row_end && col_start<=col_end)
     {
        for(col=col_start;col<=col_end;col++) //topmost row
        {
            ans.push_back(matrix[row_start][col]);
            
        }
        
        row_start++;

        for(row=row_start;row<=row_end;row++) //rightmost column
        {
            ans.push_back(matrix[row][col_end]);
            
        }
        
        col_end--;
   if(row_start<=row_end) 
        {
            for(col=col_end;col>=col_start;col--)//bottomost row
        {
            ans.push_back(matrix[row_end][col]);
            
        }
        
        }
        
        row_end--;
      if(col_start<=col_end)
      {
        for(row=row_end;row>=row_start;row--) //leftmost column
        {
            ans.push_back(matrix[row][col_start]);
            
        }
      }
        col_start++;
        

     }
     return ans ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends