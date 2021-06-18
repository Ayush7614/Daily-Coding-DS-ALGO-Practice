/*
Find the minimum and maximum amount to buy all N candies

In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided. There is also an attractive offer by the candy store. We can buy a single candy from the store and get at most K other candies (all are different types) for free.

Find the minimum amount of money we have to spend to buy all the N different candies.
Find the maximum amount of money we have to spend to buy all the N different candies.
In both cases, we must utilize the offer and get the maximum possible candies back. If k or more candies are available, we must take k candies for every candy purchase. If less than k candies are available, we must take all candies for a candy purchase.

Examples: 

Input :  
price[] = {3, 2, 1, 4}
k = 2
Output :  
Min = 3, Max = 7
Explanation :
Since k is 2, if we buy one candy we can take 
atmost two more for free.
So in the first case we buy the candy which 
costs 1 and take candies worth 3 and 4 for 
free, also you buy candy worth 2 as well.
So min cost = 1 + 2 = 3.
In the second case we buy the candy which 
costs 4 and take candies worth 1 and 2 for 
free, also We buy candy worth 3 as well.
So max cost = 3 + 4 = 7.

One important thing to note is, we must use the offer and get maximum candies back for every candy purchase. So if we want to minimize the money, we must buy candies at minimum cost and get candies of maximum costs for free. To maximize the money, we must do the reverse. Below is an algorithm based on this.

First Sort the price array.

For finding minimum amount :
  Start purchasing candies from starting 
  and reduce k free candies from last with
  every single purchase.

For finding maximum amount : 
   Start purchasing candies from the end 
   and reduce k free candies from starting 
   in every single purchase.

*/


#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector <int> v;
         vector <int> v1;
        for(int i=0;i<N;i++)
        {
            v.push_back(candies[i]);
        }
        sort(v.begin(),v.end());
        int mn = 0,mx =0;
        if(K>N)
        mn = v[0];
        else
        {
            for(int i=0;i<v.size();i++)
            {
                mn += v[i];
                for(int j=0;j<K;j++)
                {
                    if(v.size()==0)
                    break;
                    v.pop_back();
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            v1.push_back(candies[i]);
        }
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        if(K>N)
        mx = v1[0];
        else
        {
            for(int i=0;i<v1.size();i++)
            {
                mx += v1[i];
                for(int j=0;j<K;j++)
                {
                    if(v1.size()==0)
                    break;
                    v1.pop_back();
                }
            }
        }
        return {mn,mx};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends





