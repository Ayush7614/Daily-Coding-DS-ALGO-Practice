/*                  LEETCODE PROBLEM - 342   
                        POWER OF FOUR

    Given an integer n, return true if it is a power of four. Otherwise, return false.
    An integer n is a power of four, if there exists an integer x such that n == 4x.

    I am adding 3 Different Type of Solution Here, last one uncommented is the best approach


    ************1. Using Recursion************

        class Solution {
        public:
            bool isPowerOfFour(int n) {
                if(n < 1){
                    return false;
                }
                if(n == 1){
                    return true;
                }
                return n % 4 == 0 && isPowerOfFour(n / 4);
            }
        };

    Solving this problem using recursion will increase the time complexity in the program whereas space complexity remains constant

    ************2. Naive Solution************

        class Solution {
        public:
            bool isPowerOfFour(int n) {
                if(n <= 0){
                    return false;
                }
                for(int i = 0; i < 32; i += 2){
                    if(n == (1 << i)){
                        return true;
                    }
                }
                return false;
            }
        };

    This solution uses a for-loop in the program

    ************3. BIT MANIPULATION Solution ************
    
    This solution s hard to understand but problem is solved without any loops and recursion
*/

class Solution {
public:
	bool isPowerOfFour(int n) {
        //Here we return false if Number is less than 0 as a negative number cannot be the power of 4

        if(n <= 0){
			return false;
		}

        //Here use use a Bit-wise '&' operator to compare n and n-1
        //Lets assume n is 7 which is "111" in Binary then n-1 (6) which is "110" in binary
        //Hence 111 & 110 != 0, return false will be called  
		if(n & (n - 1)){
			return false;
		}

        //If both of the above has'nt been called the program will call this return statement
		return !(n & (0xAAAAAAAA));
	}
};

/*

0xAAAAAAAA is just a pattern in which set bits present at an even position (seeing from right to left)
(0xAAAAAAAA) => 10101010101010101010101010101010
So, if we AND number which is power of 4 with (0xAAAAAAAA) then the result is always 0.

*/
