
/*Implementation of Maximal Rectangle problem from LeetCode

Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

Link of the problem: https://leetcode.com/problems/maximal-rectangle/

*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MaximalRectangle 
{
	public:
    //In this function, we find next smallest element of each element
	vector<int> NSE(vector<int> v)
	{
		vector<int> nse(v.size(), v.size());
		stack<int> stk;
		for(int i=0; i<v.size(); i++)
		{
			while(!stk.empty() && v[stk.top()]>v[i])
			{
				nse[stk.top()]=i;
				stk.pop();
			}
			stk.push(i);
		}
		return nse;
	}
	
	//In this function, we will find previous smallest element of each element
	vector<int> PSE(vector<int> v)
	{
		vector<int> pse(v.size(), -1);
		stack<int> stk;
		for(int i=v.size()-1; i>=0; i--)
		{
			while(!stk.empty() && v[stk.top()]>v[i])
			{
				pse[stk.top()]=i;		
				stk.pop();
			}
			stk.push(i);
		}
		return pse;
	}
    
    int maximalRectangle(vector<vector<char>>& matrix) 
	{
        if(matrix.empty()) return {};
        
        int r= matrix.size();
        int c= matrix[0].size();
        
        if(r==0)
            return 0;
            
        if(r == 1 && c == 1) 
			return matrix[0][0] - '0';
        
        vector<vector<int>> v(r, vector<int>(c));
        
        for (int i = 0; i <r; i++) 
		{
        	for (int j = 0; j < c; j++)
                v[i][j]= matrix[i][j]=='1'?1: 0;
        }
        
        for (int i = 1; i < r; i++) 
		{
 
        	for (int j = 0; j < c; j++)
            	if (v[i][j])
                	v[i][j] += v[i - 1][j];
        }
		
        int area;
		for(int i=0; i<r ;i++)
		{
			vector<int> nse=NSE(v[i]);	
			vector<int> pse=PSE(v[i]);
		
			for(int j=0;j<c;j++)
				area = max(area, v[i][j]*(nse[j]-pse[j]-1));
		}
		return area;
    }
    
    
};

int main()
{	
	MaximalRectangle ob;

	int r,c;
	char value;
	cin>>r;
	cin>>c;
	vector<vector<char>> v(r);
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>value;
			v[i].push_back(value);
		}
	}
	int area = ob.maximalRectangle(v);
	cout<<area;
}

/*

Time Complexity: O(R x C)
Only one traversal of the matrix is required, so the time complexity is O(R X C)

Space Complexity: O(C)
Stack is required to store the columns, so so space complexity is O(C)

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = []
Output: 0

Example 3:

Input: matrix = [["0"]]
Output: 0

Example 4:

Input: matrix = [["1"]]
Output: 1

Example 5:

Input: matrix = [["0","0"]]
Output: 0

*/