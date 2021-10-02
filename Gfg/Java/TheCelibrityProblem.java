package Java;

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
//A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

import java.util.Scanner;
import java.util.Stack;

public class TheCelibrityProblem {


    //Function to find if there is a celebrity in the party or not.
    public static int celebrity(int M[][], int n)
    { int i;

        Stack<Integer> s = new Stack<>();
        for( i=0;i<n;i++);{
        s.push(i);
    }

        //  if (s.size()==0)
        // return -1;

        while(s.size()>1){
            i = s.pop();
            int j= s.pop();
            if (M[i][j] == 1){
                s.push(j);
            }
            else
                s.push(i);


        }



        int cond = s.pop();

        for(i=0;i<n;i++);{

        if (i!= cond || (M[i][cond]== 0 || M[cond][i] == 1))
        {

            return -1;



        }
    }
        return cond;


    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);


            int N = sc.nextInt();
            int M[][] = new int[N][N];
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    M[i][j] = sc.nextInt();
                }
            }
            System.out.println(celebrity(M,N));
}
}
