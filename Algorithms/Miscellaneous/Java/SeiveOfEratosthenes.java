/* Seive Of Eratosthenes is an algorithm which tells number of prime numbers in a range of 1 to n */

import java.io.*;
import java.util.*;
class SeiveOfEratosthenes
{
    void SeiveOfEratosthenes(int n)
    {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
        // Initializing all inputs as prime
            prime[i] = true;
        // loop for 2 to root n , as if a number is prime it can only be divided till root of itself
        
        for (int p = 2; p * p <= n; p++)
        {
            // If prime[p] is not changed it is a prime
            
            if (prime[p] == true)
            {
                // Update all multiples of p
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
 
        //Print prime numbers
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
                System.out.print(i + " ");
        }
    }
    public static void main(String[] args) throws IOException{

        Scanner scn = new Scanner(System.in);
        int n;
        System.out.println("Enter the range upto which you want to print prime numbers :");
        // Taking user input
        n = scn.nextInt();

        System.out.println("Following are the prime numbers in the range 1 to " +n);

        SeiveOfEratosthenes obj = new SeiveOfEratosthenes();

        obj.SeiveOfEratosthenes(n);



        
    }
}