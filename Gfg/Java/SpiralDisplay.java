// In this question, we have to display the spiral in anti-clockwise direction
// we can do it by considering each row and column as wall

import java.util.*;

public class SpiralDisplay
{
    public static void main(String[] args)
    {
        // Taking input from user
        Scanner scn = new Scanner(System.in);
        // row
        int n = scn.nextInt();
        // column
        int m = scn.nextInt();

        int[][] arr = new int[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j] = scn.nextInt();
            }
        }
        printSpiral(arr);
    }
    public static void printSpiral(int[][] arr)
    {
        int n = arr.length;
        int m = arr[0].length;

        int rs = 0, re = n-1;
        int cs = 0,ce = m-1;
         
         int count = 1;

        while(count <= n*m)
        {
            // for left wall print
            for(int i=rs;i<=re && count <= n*m;i++)
            {
                System.out.print(arr[i][cs]+" ");
                count++;
            }
            cs++;

            // for bottom wall print
            for(int i=cs;i<=ce && count <= n*m;i++)
            {
                System.out.print(arr[re][i]+" ");
                count++;
            }
            re--;

            // for right wall
            for(int i=re;i>=rs  && count <= n*m;i--)
            {
                System.out.print(arr[i][ce]+" ");
                count++;
            }
            ce--;
            
            // upper wall
            for(int i=ce;i>=cs && count <= n*m;i--)
            {
                System.out.print(arr[rs][i]+" ");
                count++;
            }
            rs++;
        }
        System.out.println();
    }
}