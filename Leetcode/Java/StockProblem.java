import java.util.*;
import java.io.*;

class StockProblem
{
	public static void main (String[] args) throws IOException
	{
        Scanner sc  = new Scanner(System.in);
        int n = sc.nextInt();
        int prices[] = new int[n];
        for(int i=0;i<n;i++)
        {
            prices[i]=sc.nextInt();
        }
        int min=Integer.MAX_VALUE;
        int ans=0;
        for(int i=0;i<prices.length;i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
            }
            else
                ans=Math.max(ans, prices[i]-min);
        }
        System.out.println(ans);
    }
}