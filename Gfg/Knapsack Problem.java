
import java.util.*;https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t-->0){
		    int n = scn.nextInt();
		    int w = scn.nextInt();
		    
		    int[][] dp = new int[n+1][w+1];
		    for(int[] d: dp)
		        Arrays.fill(d, -1);
		    int[] values = new int[n];
		    int[] weights = new int[n];
		    for(int i = 0;i<n;i++){
		        values[i] = scn.nextInt();
		    }
		    for(int i = 0;i<n;i++){
		        weights[i] = scn.nextInt();
		    }
		    System.out.println(knapSack_01_Rec(weights, values, w,n, dp));
		}
	}
	public static int knapSack_01_Rec(int[] weight, int[] value, int cap, int n, int[][] dp){
	    int N = n;
	    int Cap = cap;
	    for(n = 0;n<=N;n++){
	        for(cap = 0;cap<=Cap;cap++){
                if(cap == 0 || n == 0){
                    dp[n][cap] =0;
                    continue;
                }
                
                int maxProfit = 0;
                if(cap-weight[n-1]>=0){
                    maxProfit = Math.max(maxProfit,dp[n-1][cap-weight[n-1]]+value[n-1]);
                }
                maxProfit = Math.max(maxProfit, dp[n-1][cap]);
                dp[n][cap] = maxProfit;
	        }
	    }
	    return dp[N][Cap];
    }
}
