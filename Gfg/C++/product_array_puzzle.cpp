/*Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.


*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
    {
        //code here
        vector<long long int>v;
        long long prod = 1;
        long long count0 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                prod*=nums[i];
            }
            else
            {
                count0++;
            }
        }
        for(int j=0; j<n; j++)
        {
            if(count0==0)
            {
                long long a = prod;
                v.push_back(a/nums[j]);
            }
            else
            {
                if(nums[j]!=0)
                {
                    v.push_back(0);
                }
                else if(count0==1)
                {
                    v.push_back(prod);
                }
                else
                {
                    v.push_back(0);
                }
            }
        }
        return v;
    }
};


int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
