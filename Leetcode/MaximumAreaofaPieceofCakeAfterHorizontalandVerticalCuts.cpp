/* 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Medium

============================================================================

Problem Statement

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.


Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.


================================================================================


SOLUTION:*/


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int s=max(horizontalCuts[0], h-horizontalCuts.back());
        for(int i=1; i<horizontalCuts.size(); i++){
            int a=horizontalCuts[i]-horizontalCuts[i-1];
            s=max(s, a);
        }
        
        int r=max(verticalCuts[0], w-verticalCuts.back());
        for(int i=1; i<verticalCuts.size(); i++){
            int a=verticalCuts[i]-verticalCuts[i-1];
            r=max(r, a);
        }
        

        return long(r)*s %1000000007;        
    }
};
