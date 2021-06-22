// You are given a number N. Find the total number of setbits in the numbers from 1 to N. 

//Test Cases :- 

// Input: N = 3
// Output: 4
// Explaination: 
// 1 -> 01
// 2 -> 10 
// 3 -> 11. 
// So total 4 setbits.

// Input: N = 4
// Output: 5
// Explaination:
// 1 -> 01
// 2 -> 10
// 3 -> 11 
// 4 -> 100. 
// So total 5 setbits.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106

import java.io.*;

class GeeksForGeeks{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //Input test cases.
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            //Input N.
            int N = Integer.parseInt(in.readLine());
            answer ob = new answer();
            System.out.println(ob.countBits(N));
        }
    }
}

class answer{
    //*Naive Approach -
    //*Time Complexity - O(NlogN)
    //It will give you a TLE error for the given constraints.
    //why ? Let's analyze that.
    //Because for every number from 1 to N.
    //you are calling a function that is counting the number of setbits in number.
    //the recursive call of the function countSetBitsUtil is decreasing by 2 in every call.
    //So the time complexity will be O(NlogN) - for every N there is a recursive call for finding the setbits.

    // static int countBits(int N){
    //     int bitCount = 0;
    //     for (int i = 1; i <= N; i++)
    //         bitCount += countSetBitsUtil(i);
    //     return bitCount;
    // }

    // static int countSetBitsUtil( int x)
    // {
    //     if (x <= 0)
    //         return 0;
    //     return (x % 2 == 0 ? 0 : 1) +
    //            countSetBitsUtil(x / 2);
    // }

    //Optimized Approach.
    //*Time complexity - O(logN)
    //*Space complexity - O(1)
    int countBits(int N){
        int two = 2;
        N = N+1;
        int count = N/2;
        while(two <= N){
            int totalpair = N/two;
            count += (totalpair >> 1) * two;
            count += (totalpair % 2 == 1) ? (N % two) : 0;
            two = two << 1;
        }
        return count;
    }
    //For N = 4.
    
    //N = 4+1 = 5
    //count = 5/2 = 2
    //First iteration - two <= N == true
    //totalpair = 5/2 = 2
    //count += totalpair / 2 * two = 2/2 * 2 = 1, count = 2+2 = 4.
    //count += (totalpair % 2 == 1) ? (N % two) : 0 = 0, count = 4.
    //two = 4

    //Second iteration - two <= N == true
    //totalpair = 5/4 = 1
    //count += totalpair/2 * two = 1/2 * 2 = 0, count = 4
    //count += (totalpair % 2 == 1) ? (N % two) : 0; count = 4.
    //two = 6

    //Third iteration - two <= N == true
    //totalpair = 5/6 = 0
    //count += totalpair/2 * two = 0/2 * 2 = 0, count = 4
    //count += (totalpair % 2 == 1) ? (N % two) : 0; count = 4
    //two = 8

    //Fourth iteration - two <= N == false
    //count = 4 (answer).
}