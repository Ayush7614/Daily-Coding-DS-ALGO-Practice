/*                                      LEETCODE PROBLEM #123
                                    BEST TIME TO BUY AND SELL STOCKS - III

    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    Find the maximum profit you can achieve. You may complete at most two transactions.
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

    Example 2:

    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

    Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.

    Example 4:
    Input: prices = [1]
    Output: 0

    **********APPROACH 1**********
        BRUTE FORCE APPROACH - 1

    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            for(int i=0; i<prices.size(); i++) {
                vector<int> former(prices.begin(), prices.begin()+i);
                vector<int> later(prices.begin()+i, prices.end());
                profit = max(profit, subMaxProfit(former) + subMaxProfit(later));
            }
            return profit;
        }

    private:
        int subMaxProfit(vector<int>& prices) {
            if(prices.empty()) return 0;
            
            int profit, buyValue, evaluate;
            buyValue = prices[0];
            profit = 0;
            
            for(int j=1; j < prices.size(); j++) {

                if(prices[j] - buyValue > profit) {
                    profit = prices[j] - buyValue;
                } 
                
                if(prices[j] < buyValue) {
                    buyValue = prices[j];
                }
            }
            return profit;
        }
    };

    **********APPROACH - 2**********
*/

#include <iostream.h>
#include <vector.h>

class Solution {
public:
    int maxProfit(vector<int>& A) {

         //Already solved Best Time to Buy and Sell Stock IV, so here I am just changing K = 2;
        int K  = 2;
        int N = A.size();
        
        //Case1 - No transaction Or only one day's stock is present

        if(K<=0 || N<=1) return 0;

        //Case2 - Total number of transaction * 2 > = N

        if(2*K>=N)
        {
            int res = 0;
            for(int i=1;i<N;i++) res += max(0, A[i]-A[i-1]);
            return res;
        }

        //Case3 - General case

        int state[2*K];
        for(int i=0;i<2*K;i++)
        {
            if(i%2==0) state[i] = INT_MIN; //BUY
            else state[i] = 0; //SELL
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<2*K;j++)
            {
                if(j==0) state[j] = max(state[j], -A[i]);
                else if(j%2==0) state[j] = max(state[j], state[j-1]-A[i]);
                else if(j%2!=0) state[j] = max(state[j], state[j-1]+A[i]);
            }
        }
        return state[2*K-1];
    }
};

int main () {
        Solution s;
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k;
        cin >> n;
        vector<int> arr(n), res;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;)
            res=s.maxProfit(arr);
            for(auto i:res){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}