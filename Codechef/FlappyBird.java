
/*
 *Implementation 'Flappy Bird' problem from June CodeChef starters
 *
 *Problem name : Flappy Bird
 *Problem code : FLAPPYBD
 *Problem link : https://www.codechef.com/START5C/problems/FLAPPYBD/
 *
 */

import java.util.*;
import java.lang.*;
import java.io.*;

//In this problem we need to tell Chef if he can win the game (get the bird 
//to cross all the obstacles) and the minimum number of clicks required to win in such a case

public class FlappyBird
{
    public static void main() 
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();             //Number of obstacles
            int H=sc.nextInt();             //The bird starts at a height H
            int position[]= new int[n];     
            int heights[]= new int[n];      
            
            for(int i=0;i < n;i++) 
            position[i]=sc.nextInt();       //Position of obstacles

            for(int i=0;i < n;i++)
            heights[i]=sc.nextInt();        //Height of obstacles
        
            int i = 0;
            int pos = 0;
            int h = H;
            int nc = 0;
            boolean win = true;
            int rem;
            int ex;
            int ans = 0;
            
            //For each integer i (0≤i<xN), Chef has the option to click once when 
            //the bird is at x=i. Let's denote the bird's height (y-coordinate) at 
            //that point by j. If he clicks, the bird moves to x=i+1 and y=j+1. 
            //Otherwise, the bird moves to x=i+1 and y=j−1.
            while(i < n) 
            {
                int dist = position[i] - pos;
                h -= dist;
                nc += dist;
                if(h <= heights[i])     
                {
                    rem = heights[i]+1-h;
                    if(2 * nc < rem)
                    {
                        System.out.println("-1");   //print −1  if it is impossible to cross all the obstacles
                        win = false;
                        break;
                    }
                    else 
                    {
                        ex = rem/2 + rem%2;
                        nc -= ex;
                        ans += ex;      //the minimum number of clicks required to cross all the obstacles successfully
                        h = h + 2 * ex;
                        pos = position[i];
                        i++; 
                        continue;
                    }
                }
                //the bird crosses the ith obstacle successfully if the bird's height at x=position[i] is strictly greater than heights[i]
                else   
                {
                    pos = position[i];
                    i++;
                }
            }
            if(win)
                System.out.println(ans);    //printing the minimum number of clicks required to cross all the obstacles successfully
         }
    }
}

/*
 * Example Input -
 
   3
   1 0
   2
   1
   2 1
   1 3
   1 1
   5 10
   1 2 3 4 5
   10 11 12 13 15
   
   Example Output -
   
   2
   2
   -1
   
 */