/* Medium
1561. Maximum Number of Coins You Can Get
Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

Statement:
There are 3n piles of coins of varying size, you and your friends will take
piles of coins as follows:

In each step, you will choose any 3 piles of coins.
Of your choice, Alice will pick the pile with the maximum number of coins.
You will pick the next pile with maximum number of coins.
Your friend Bob will pick the last pile.
Repeat until there are no more piles of coins.
Given an array of integers piles where piles[i] is the number of coins in
the ith pile.

Return the maximum number of coins which you can have.

Input: piles = [9,8,7,6,5,1,2,3,4]
Output: 18
*/

/*
Greedy Problem.
To maximise the number of coins we would choose the pile with 2nd highest
number of coins (as alice will choose the first highest no matter which 3 piles
we choose) and Bob is made to choose the pile with lowest possible number of
coins
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        std::sort(piles.begin(), piles.end());
        for(int i = 0; i < (piles.size()/3) ;i++){
            ans += piles[piles.size() - 2 - i*2];
        }
        return ans;
    }
};