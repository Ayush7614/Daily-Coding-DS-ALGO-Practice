/* Implementation of Forming a Magic Square

You will be given a 3 X 3 matrix 's' of integers in the inclusive range[1,9]. We can convert 
any digit 'a' to any other digit 'b' in the range[1,9] at cost of |a-b|. Given 's', convert it into
a magic square at minimal cost. Print this cost on a new line.

Note: The resulting magic square must contain distinct integers in the 
inclusive range[1,9].

Link to the problem: https://www.hackerrank.com/challenges/magic-square-forming/problem
*/

import java.io.*;
import java.util.*;

/*We define a magic square to be an n x n matrix of distinct positive integers from 1 to n^2 
where the sum of any row, column, or diagonal of length N is always equal to the
same number: the magic constant.*/

public class MagicSquare
{
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        int a[][]=new int[3][3];
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=sc.nextInt();   //reading matrix of order 3x3
        
        //Storing all the possible Magic Square matrix of order 3x3 in a 2D array
        int b[][]={{8,1,6,3,5,7,4,9,2}, 
        {8,3,4,1,5,9,6,7,2},
        {6,7,2,1,5,9,8,3,4},
        {4,9,2,3,5,7,8,1,6},
        {6,1,8,7,5,3,2,9,4},
        {4,3,8,9,5,1,2,7,6},
        {2,7,6,9,5,1,4,3,8},
        {2,9,4,7,5,3,6,1,8}};       
        
        //Now comparing the input array to all possible Magic Square of order 3x3
        //And calculating its minimum cost
        int min=Integer.MAX_VALUE;  //storing the maximum number in min
        for(int i=0 ; i<b.length ; i++)
        {
            int total=0;
            for(int j=0 ; j<b[i].length ; j++)
            {
                total += Math.abs(a[j/3][j%3] - b[i][j]);      //calculating the cost
            }
            if(total < min)
            min = total;
        }
        System.out.println(min);    //printing the minimum cost     
    }
}

/* 
 * Test case 1:
 * 
 * Sample Input-
 * 
 * 4 9 2
 * 3 5 7
 * 8 1 5
 * 
 * Sample Output-
 * 
 * 1
 * 
 * Test case 2:
 * 
 * Sample Input-
 * 
 * 4 8 2
 * 4 5 7
 * 6 1 6
 * 
 * Sample Output-
 * 
 * 4
 * 
 * Time complexity - O(9 x 8 x 9)
 */