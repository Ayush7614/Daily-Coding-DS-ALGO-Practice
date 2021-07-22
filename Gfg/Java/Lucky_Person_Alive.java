//Link to the Problem -
//https://practice.geeksforgeeks.org/problems/lucky-alive-person-in-a-circle1229/1/?category[]=Bit%20Magic&category[]=Bit%20Magic&problemStatus=solved&page=1&query=category[]Bit%20MagicproblemStatussolvedpage1category[]Bit%20Magic

import java.util.*;
//Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle.
//Note k is 2 for this specific problem.
//According to the problem statement :-
//In every iteration till only one person is alive, we will be skipping k-1 persons and killing the kth person.
//Note: Once the person is killed, it can't be killed anymore time, so basically we're skipping already killed person.
//Some points to note :- 
//In first iteration all the even positioned person will be killed.
//for second round there will be two cases.

//case 1 :- N is even - 
//for ex :- N = 8.
//person killed in the first round are 2, 4, 6, 8.
//Then in second round we have 1, 3, 5, 7 at position 1, 2, 3, 4 respectively.

//case 2:- N is odd -
//for ex :- N = 9
//person killed in the first round are 2, 4, 6, 8.
//Then in second round we have 1, 3, 5, 7, 9 at position 1, 2, 3, 4, 5 respectively.

// If n is even and a person is in position x in current round, then that person was in position 2x - 1 in previous round.
// If n is odd and a person is in position x in current round, then that person was in position 2x + 1 in previous round.
// From above facts, we can recursively define the formula for finding position of survivor. 

//let f(n) be the position of survivor for n input.
//Then the value of f(n) can be recursively be defined as below -
//If n is even, f(n) = 2f(n/2) - 1.
//If n is odd, f(n) = 2f(n-1/2) - 1.

// The Trick -
// Whenever someone talks about the powers of 2 the first word that comes to mind is “binary”.
//The solution to this problem is much is easier and shorter in binary than in decimal.
//There is a trick to this. Since we need to deduct the biggest possible power of in binary that number is the Most Significant Bit.
//In the original Josephus problem, there were 40 other soldiers along with Josephus which makes n = 41.
//41 in binary is 101001. If we shift the MSB
//i.e. the leftmost 1 to the rightmost place we get 010011 which is 19 (in decimal) which is the answer.
//This is true for all cases. This can be done easily using bit manipulation.

//For doing so we have to follow thw following steps :-

//N can be represented as, N = 2^x + L.
//powerOf2 function is used to find the value of x.
//for N = 10, x will be 8.
//10 in binary = 1010, here L = 010 which is highest power of 2
//and then we will find the value of L.
//by doing L = N - x;
//which will be 2 in case of 10.
//then, 2 * L + 1, will be 5.
//which is our answer
//Example -
//N = 10
//nearest value to the 10 by using 2^x will be 8, and the value of x which we have to find will be 4.
//Then to find L we have to minus the value of x from N, that will be 2 in this case.
//N = 2^x + L, N = 2^4 + 2, N = 10, LHS = RHS.
//After we get the value of L we are returning L*2+1, is 3 in this case.
//Which will be our answer.

//why we are doing so ?
//By getting the value of x(highest power of 2), we get to know which person will be killed at last.
//Now for every n,
//the right position for Josephus can be found out by
//deducting the biggest possible power of 2 from the number and adding 1 to it and we get the answer.

//DRY run these sample testcases : to get a better idea of the problem.
//*Before starting to code.

//N     answer
//1       1
//2       1
//3       3
//4       1
//5       3
//6       5
//7       7
//8       1
//9       3

class Lucky_Person_Alive{
    //function to return the position of survivor.
    int find(int N){
        int L = N - powerOf2(N);
        return ((L << 1 )+ 1);
      //It can also be written as -
      //return l * 2 + 1;
      //because multiplying by 2 is noting but shifting every bit by one place to the left, that's why we're shifting it to left by 1.
    }
    //function to find the value of x, 2^x
    int powerOf2(int n) {
        int i = 1;
        while (i * 2 <= n)
            i *= 2;
        return i;
    }
}

class geeks
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        //Input number of test cases.
        int t = sc.nextInt();
        while(t-- > 0)
        {
            //Input N - Number of people standing in the circle.
            int N = sc.nextInt();
            Lucky_Person_Alive ob = new Lucky_Person_Alive();
            System.out.println(ob.find(N));
        }
        sc.close();
    }
}
//Time complexity = O(log n).
//Space complexity = O(1).


                                //*********fact********//
//If N is true power of 2 then our answer will be 1 always. DRY these example - 2, 4, 8, 16, etc.
//We will be getting only ODD answer because all the EVEN ones will be killed in the first iteration.

//Note - 
//The above question can also be done using linked list.
//But this method is the shortest of all and easiest to implement.