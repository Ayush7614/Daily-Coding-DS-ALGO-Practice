//User Name :yellowberard
// Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.
// link:https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/?category[]=Matrix&category[]=Matrix&page=1&query=category[]Matrixpage1category[]Matrix#

// Example 1:

// Input:
// n = 3, m = 3, x = 62
// matrix[][] = {{ 3, 30, 38},
//               {36, 43, 60},
//               {40, 51, 69}}
// Output: 0
// Example 2:

// Input:
// n = 1, m = 6, x = 55
// matrix[][] = {{18, 21, 27, 38, 55, 67}}

// Time Complexity:O(n+m)
// Space Complexity:O(1)


// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
         bool flag=false;
    int r=0,c=m-1;
    while( r<n and c>=0 )
    {
        if(matrix[r][c]==x)
        {
            flag=true;
            break;

        }
        else if(matrix[r][c]>x) //if number to be searched is smaller than we move right side
        {
            c--;
        }
        else        //if number to be searched is greater then we move downward
        {
            r++;
        }
    }
        return flag;
    }
};

// { Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

  // } Driver Code Ends