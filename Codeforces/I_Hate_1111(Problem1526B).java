package com.tirth;
/*
Language - JAVA
Problem Statement -
You are given an integer x. Can you make x by summing up some number of 11,111,1111,11111,…?
(You can use any number among them any number of times).
Input -
The first line of input contains a single integer t (1≤t≤10000) — the number of testcases.
The first and only line of each testcase contains a single integer x (1≤x≤10^9) — the number you have to make.
Output -
For each testcase, you should output a single string. If you can make x, output "YES" (without quotes).
Otherwise, output "NO".
You can print each letter of "YES" and "NO" in any case (upper or lower).
Test Cases
Input -
    3
    33
    144
    69
Output -
    YES
    YES
    NO
Explanation -
33 = 11 + 11 + 11
144 = 111 + 11 + 11
69 - no combination possible
*/

/*
Logic -
1111 = 1100 + 11 = 11*101
11111 = 11100 + 11 = 111*100 + 11
111111 = 111000 + 111 = 111*1001
.
.
.
any series of 1111.. can be decomposed to a*11 + b*111, where a and b are positive integers
By Chicken McNugget Theorem all number greater than mn - m - n can be expressed as am + bm ,
where a and b are positive integers
Thus any number greater than 11*111 - 11 - 111 = 1099 can be expressed as a*11 + b*111
Now we only have to check for number smaller than 1099
that can be done by Brute force
*/

import java.util.Scanner;

public class Main {
    public static boolean solve(long n){
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 10; j++)
            {
                if ((11 * i) + (111 * j) == n)
                {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner (System.in);
        int T = sc.nextInt();
        while(T!=0)
        {
            long n = sc.nextLong ();
            if (n <= 1099)
            {
                if (solve(n))
                {
                    System.out.println ("YES");
                }
                else
                {
                    System.out.println ("NO");
                }
            }
            else
            {
                System.out.println ("YES");
            }
            T--;
        }
    }
}