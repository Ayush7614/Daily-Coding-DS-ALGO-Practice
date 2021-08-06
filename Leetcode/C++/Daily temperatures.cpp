//LINK TO THE PROBLEM:https://leetcode.com/problems/daily-temperatures/

//AIM:Return an array answer such that answer[i] is the number of days
// you have to wait after the ith day to get a warmer temperature.

//EXAMPLE:
/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/
//SOLUTION:
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//function to get a warmer temperature.
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //answer vector holding rise
        vector<int> ans(temperatures.size(),0);
        //temporary stack holding temp and its index
        stack<pair<int,int>>s;
        for(int i=temperatures.size()-1;i>=0;i--)
       {
            //traversing from the back finding if the next has a rise in temp
             int curr=temperatures[i];
           while(!s.empty()&&curr>=s.top().first)//found a warmer temp
           {
              s.pop(); 
           }
           ans[i]=s.empty()?0:s.top().second-i;//if it is itself the warmest day returning 0 else providing the diff
           s.push(pair<int,int>(temperatures[i],i));//pushing the temp and index
       }
      return ans;
    }
int main()
{
   vector<int>temperatures = {73,74,75,71,69,72,76,73};
    vector<int>ans=dailyTemperatures(temperatures);
    cout<<"[";
    for(int i=0;i<ans.size()-1;i++)
    {
        cout<<ans[i]<<",";//Printing solution!!
    }
    cout<<ans[ans.size()-1];
    cout<<"]";
    return 0;
}