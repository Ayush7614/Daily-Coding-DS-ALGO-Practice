/*Implementation of Bitwise Tuples problem from CodeChef*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
import java.lang.*;
import java.io.*;

class Bitwise_tuples
{                   
   public static void main (String[] args) throws java.lang.Exception
   {
        
       try{
            Scanner sc=new Scanner(System.in);
            long t=sc.nextLong();
            long mod=1000000007; //answer to the problem modulo 10^9+7
            int a[]=new int[1000002];
            a[1]=2;
            for(int i=2;i<1000002;i++)
            a[i]=(2*a[i-1])%1000000007;
            while(t-->0)
            {
                int n=sc.nextInt();
                int m=sc.nextInt();
                long x=a[n]-1;
                long temp=1;
                while(m>0)                //modular method to find the power
                {
                    if(m%2==1)
                    temp=x*temp%mod;        //answer to the problem modulo 10^9+7
                    x=x*x%mod;              //answer to the problem modulo 10^9+7
                    m=m/2;
                }
            
                System.out.println(temp);
            }
        }catch(Exception e)
        {return;}
        }
}

/*
 * Sample Input-
   
   4
   1 2
   2 2
   4 2
   8 4
   
 * Sample Output-
   
   1
   9
   225
   228250597
   
 */