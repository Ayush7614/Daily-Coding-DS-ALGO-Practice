//Link to the problem
/*
  https://leetcode.com/problems/number-of-1-bits/
 */

//According to the problem:

//AIM: Return the number of '1' bits it has (also known as the Hamming weight).

/*
 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

*/
//SOLUTION:

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        for(int i = 0; i<32; i++){//traversing the complete 32 bit integer
            if(n & 1 == 1)//if found 1
                x++;//add to sol
            n = n>>1;//check next bit
        }
        return x;//return total number of 1 bits.
    }
};