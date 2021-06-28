// This is the solution for the problem : Best Time to Buy and Sell Stocks - 1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*                  BRUTE FORCE APPROACH

class Solution {
public:
    int maxProfit(vector<int>& prices) {    
        int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
};


TIME COMPLEXITY : O(N^2).  Loop Runs (N(N-1))/2 Times
SPACE COMPLEXITY : O(1)
*/


//This is a Better Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, currProfit = 0, buy = prices[0];
        for(int i = 0; i < prices.size(); i++) {
            currProfit = prices[i] - buy;
            if(currProfit > maxProfit){
                maxProfit = currProfit;
            }
            else if(currProfit < 0){
                buy = prices[i];
            }
        }
        return maxProfit;
    }
};


//TIME COMPLEXITY: O(N)
//SPACE COMPLEXIITY: O(1)