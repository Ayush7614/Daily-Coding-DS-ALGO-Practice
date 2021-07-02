/*Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

Example:

    Input : n =10
    Output : 2 3 5 7

    Input : n = 20
    Output: 2 3 5 7 11 13 17 19
*/
//---------------------------------------------Solution------------------------------------------------------------
package com.viki.session2;

import java.util.Scanner;

public class SieveofEratorthenes {
    public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    //take the input n
    int n  = sc.nextInt();

    //Take the array of size n + 1
    int[] prime = new int[n + 1];

    //iterate the loop from 2 to n(beacuse 2 is the smallest prime number)
    for(int i = 2; i<=n; i++){
        //check if the element is unmarked(if 0 then it is unmarked)
        if(prime[i] == 0){
            //the we iterate this loop to marked the multiples of the element(that is why we jumped i steps(because we have to crossout the multiples of i)
            for (int j = i*i; j <= n; j += i) {
                //then we marked the i
                prime[j] = 1;
            }
        }
    }

    //then we use to iterate the loop from  2 to n
    for (int i = 2; i<=n; i++){
        //then we use to check which value is unmarked
        if(prime[i] == 0){
            //and print it
            System.out.println(i);
        }
    }
}
}
