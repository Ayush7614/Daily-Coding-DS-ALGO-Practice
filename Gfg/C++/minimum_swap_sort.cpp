/*Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n =nums.size();
	    vector<pair<int,int> > v(n);
	    for(int i=0; i<n; i++)
	    {
	        v[i] = {nums[i],i};
	    }
	    sort(v.begin(),v.end());
	    int c = 0;
	    for(int i=0; i<n; i++)
	    {
	        if(v[i].second == i) continue;
	        else
	        {
	            c++;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    return c;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  
