//Link to solution:
//https://leetcode.com/problems/flood-fill/

/*Algorithm:
 We will use DFS and check all 4 adjacent grid block. If the adjacent blocks have same color as image[sr][sc] then 
 replace its color with new given color. Keep on doing this and return the modified image vector.
 */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int v[51][51],int val)
    {
         int m=image.size();
        int n=image[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n ) 
            return;
        if(v[sr][sc]==1 || image[sr][sc]!=val)
            return ;
        
     
        v[sr][sc]=1;
        image[sr][sc]=newColor; // replacing with mew color
        dfs(image,sr+1,sc,newColor,v,val); //checking adjacent blocks
        dfs(image,sr-1,sc,newColor,v,val);
        dfs(image,sr,sc+1,newColor,v,val);
        dfs(image,sr,sc-1,newColor,v,val);
        
            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int v[51][51],i,j;
        
        int m=image.size();
        int n=image[0].size();
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                v[i][j]=0;
        int val=image[sr][sc];
        
        dfs(image,sr,sc,newColor,v,val);
        
        return image;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
    int n, m;
	while(tc--)
    {
	
		cin >> n >> m;
		vector<vector<int>>image;
		for(int i = 0; i < n; i++)
        {
			for(int j = 0; j < m; j++)
            {
				cin >> image[i][j];
			}
		}
        int sr,sc,newColor;
        cin>>sr,sc,newColor;
		Solution obj;
		vector<vector<int>>ans= obj.floodFill(image,sr,sc,newColor);

        for(int i = 0; i < n; i++)
		    for(int j = 0; j < m; j++)
				cout<<ans[i][j]<<" ";

        cout<<endl;
	}

   
	return 0;
}  // } Driver Code Ends

/*
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
*/