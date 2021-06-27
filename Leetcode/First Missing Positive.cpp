#include <bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
   int n = nums.size();
   int j = 0;
      for(int i=0; i<n; i++)
       {
         int curr = nums[i];
           while(curr>=1 && curr<=n && nums[curr-1]! = curr)
            {
             int temp = nums[curr-1];
                nums[curr-1] = curr;
                curr = temp;
            }
       }
       for(int i=0; i<n; i++)
        {
           if(nums[i]! = i+1) 
             return i+1; 
        }
        return n+1;
}
    
int main()
{
  vector <int>a ={3,4,-1,1};
  cout<<firstMissingPositive(a)<<endl;
  return 0;
}
/*
Input :- 3,4,-1,1
Output :- 2
*/
