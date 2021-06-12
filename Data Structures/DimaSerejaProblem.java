/*
Sereja and Dima play a game. The rules of the game are very simple. The players have n cards in a row. Each card contains a number, all numbers on the cards are distinct. The players take turns, Sereja moves first. During his turn a player can take one card: either the leftmost card in a row or the rightmost one. The game ends when there is no more cards. The player who has the maximum sum of numbers on his cards by the end of the game wins.
Sereja and Dima are being greedy. Each of them chooses the card with the larger number during his move.Inna is a friend of Sereja and Dima. She knows which strategy the guys are using, so she wants to determine the final score, given the initial state of the game. Help her.

Input:
4
4 1 2 10
Output:
12 5
*/

import java.util.*;

public class DimaSerejaProblem
{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        
        // taking input
        int n = scn.nextInt();

        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.nextInt();
        }
      printDimaSeraja(arr);
    }
    public static void printDimaSeraja(int[] arr)
    {
        int n  = arr.length;
        int i = 0,j = n-1;
        int first = 0,second = 0;

        // In each iteration ach player get  a chance to choose the  highest number
        for(int k=0;k<n;k++)
        {
           if(k%2 ==0)
           {
                  if(arr[i] > arr[j])
                  {
                      first += arr[i];
                      i++;
                  }
                  else
                  {
                    first += arr[j];
                    j--;
                  }
           }
           else
           {
                  if(arr[i] > arr[j])
                  {
                      second += arr[i];
                      i++;
                  }
                  else
                  {
                    second += arr[j];
                    j--;
                  }
           }
        }
        System.out.println(first+" "+second);
    }
}
