/*LEETCODE GAS STATION PROBLEM

https://leetcode.com/problems/gas-station/

AIM: 

There are N gas stations along a circular route, where the amount of gas at station i is arr[i]. We have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).

 We have to return minimum starting gas station’s index if you need to travel around the circuit once, otherwise return -1.

Solution has :Time Complexity: O(n)
              Space Complexity: O(1)

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3

*/

#include<bits/stdc++.h>
using namespace std;

 class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0;
        int curr_gas=0;
        int prev_gas=0;
        
        for(int i=0; i<gas.size(); i++)
        {
            curr_gas+= (gas[i]-cost[i]);
            
            if(curr_gas<0)
            {
                start=i+1;
                prev_gas+= curr_gas;
                curr_gas=0;
            }
        }
        
        return ((curr_gas+prev_gas>=0)? (start):-1);
    }
};



// Solution Steps

// Create a start to store the valid starting index from where the car could touch all the stations.
// For each station i, fill the fuel tank with gas[i] and burn the fuel by cost[i]
// If at any point the tank is < 0 then, choose the next index as the starting point.
// At last, check if the total fuel available at the gas stations is greater than the total fuel burnt during the travel.
// Return the start
