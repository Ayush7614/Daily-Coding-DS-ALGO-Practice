#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candie = INT_MIN;
        for(int candy: candies)
            max_candie = max(max_candie,candy);
        vector<bool> res;
        for(int candy: candies)
            if(candy + extraCandies >= max_candie) res.push_back(true);
            else res.push_back(false);
        return res;
    }
};