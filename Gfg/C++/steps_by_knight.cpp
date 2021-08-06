//Link to problem: 
//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

/*Algorithm:
We will use BFS and move in all 8 possible path which can be taken by Knight. We will store the count
that the knight can take to visit a block and finally return the min steps for the destination.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int x1=KnightPos[0];
	    int x2=TargetPos[0];
	    int y1=KnightPos[1];
	    int y2=TargetPos[1];
	    
	    if(x1==x2 && y1==y2) 
	        return 0;
	        
	   queue<pair<int,int>>q;
	   int v[1001][1001]; // visited array
	   
	   for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        v[i][j]=0;
	        
	   q.push(make_pair(x1-1,y1-1));
	   
	   while(!q.empty()) //BFS traversal
	   {
	       auto temp=q.front();
	       q.pop();
	       int i=temp.first;
	       int j=temp.second;
	       
	       if((i+1)>=0 && (j+2)<n && (j+2)>=0 && (i+1)<n && v[i+1][j+2]==0)
	       {
	           v[i+1][j+2]=v[i][j]+1;
	            q.push(make_pair(i+1,j+2));
	           
	       }
	       
	       if((i-1)>=0 && (j+2)<n && (j+2)>=0 && (i-1)<n && v[i-1][j+2]==0)
	       {
	           v[i-1][j+2]=v[i][j]+1;
	            q.push(make_pair(i-1,j+2));
	           
	       }
	       
	        if((i+1)>=0 && (j-2)<n && (j-2)>=0 && (i+1)<n && v[i+1][j-2]==0)
	       {
	           v[i+1][j-2]=v[i][j]+1;
	            q.push(make_pair(i+1,j-2));
	           
	       }
	       
	       if((i-1)>=0 && (j-2)<n && (j-2)>=0 && (i-1)<n && v[i-1][j-2]==0)
	       {
	           v[i-1][j-2]=v[i][j]+1;
	            q.push(make_pair(i-1,j-2));
	           
	       }
	       
	        if((i+2)>=0 && (j+1)<n && (j+1)>=0 && (i+2)<n && v[i+2][j+1]==0)
	       {
	           v[i+2][j+1]=v[i][j]+1;
	            q.push(make_pair(i+2,j+1));
	           
	       }
	       
	       if((i+2)>=0 && (j-1)<n && (j-1)>=0 && (i+2)<n && v[i+2][j-1]==0)
	       {
	           v[i+2][j-1]=v[i][j]+1;
	            q.push(make_pair(i+2,j-1));
	           
	       }
	       
	       if((i-2)>=0 && (j+1)<n && (j+1)>=0 && (i-2)<n && v[i-2][j+1]==0)
	       {
	           v[i-2][j+1]=v[i][j]+1;
	            q.push(make_pair(i-2,j+1));
	           
	       }
	       
	       if((i-2)>=0 && (j-1)<n && (j-1)>=0 && (i-2)<n && v[i-2][j-1]==0)
	       {
	           v[i-2][j-1]=v[i][j]+1;
	            q.push(make_pair(i-2,j-1));
	           
	       }
	       
	       
	   }
	   return v[x2-1][y2-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

/*

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3

*/