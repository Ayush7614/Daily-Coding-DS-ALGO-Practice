/*
Problem: Pascal's Triangle II on LeetCode, Solution by AtrikGit6174

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 
Constraints:
--0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

The following solution is Time: O(rowindex^2) and Space O(rowIndex)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> getRow(int n) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        switch (n)
        {
            case 0:
                return {1};
            
            default:
                vector<int> ret (n+1, 0);               //initialises the ret vector with n+1 zeroes
                ret[0]= 1;
                
                for (int count=1; count<=n; count++)
                {
                    for (int i=count; i>0; i--)
                    {
                        ret[i]+= ret[i-1];  
                    }
                }
                
                return ret;
        }
        
    }
};

int main()
{

    cout<<"Enter rowIndex: ";
    int n; cin>>n;

    Solution *ob;

    auto vec= ob->getRow(n);
    cout<<"\nPascal row is: ";

    for (int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
        
    return 0;
}
