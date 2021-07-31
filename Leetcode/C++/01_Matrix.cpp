//Link to problem:
//https://leetcode.com/problems/01-matrix/

/*Algorithm :
Push all blocks in queue having value 0. Use BFS and Traverse each block according to queue . If the adjacent block is 1 and not 
out of range of grid, then update its count of nearest 0.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size(),i,j;
        int n=mat[0].size();
        
        vector<vector<int>>v(m,vector<int>(n));
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                v[i][j]=0;
        
        queue<pair<int,int>>q;
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                     q.push({i,j}); //pushing each block having value 0 in queue
                    v[i][j]=1; //marking visited
                     
                }
                   
            }
        
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}}; //storing all 4 adjacent positions
        
        while(!q.empty())
        {
            int size=q.size();
            
            for(i=0;i<size;i++)
            {
                auto a=q.front();
                int x=a.first;
                int y=a.second;
                
                q.pop();
                for(j=0;j<4;j++)
                {
                   int xx=x+dir[j][0]; 
                    int yy=y+dir[j][1];
                    
                    if(xx>=m || xx<0 || yy>=n || yy<0 || v[xx][yy]) //if block is out of range or already visited
                        continue;

                    mat[xx][yy]=mat[x][y]+1; //updating count
                    q.push({xx,yy}); //pushing to queue
                    v[xx][yy]=1;// marking visited
                    
                    
                }
            }
        }
        
        return mat;
        
        
        
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int m,n,i,j;
        cin>>m>>n;

        vector<vector<int>>mat;

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                cin>>mat[i][j];
        
       
        
        Solution obj;
        obj.updateMatrix(mat);

        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
            cout<<"\n";

        }

        
    }

    return 0;
}


/*
Input:
t=1
m=3
n=3
 mat = [[0,0,0],[0,1,0],[0,0,0]]

Output: [[0,0,0],[0,1,0],[0,0,0]]

*/
