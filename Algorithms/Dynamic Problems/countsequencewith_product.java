package bitmasking;

import java.util.ArrayList;

public class countsquencewithproductK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = { 1, 2, 3, 4 };

		System.out.println(solverecursive(arr, 0, new ArrayList<Integer>(), 8));
		solvedp(arr, 8);
	}

	// this is O(2^n) exponential time complexity
	public static int solverecursive(int[] arr, int i, ArrayList<Integer> ans, int k) {
		if (i == arr.length) {
			int prod = 1;
			for (int j = 0; j < ans.size(); j++) {
				System.out.print(ans.get(j) + " ");
				prod *= ans.get(j);
			}
			System.out.println(" -> " + prod);
			if (prod < k && ans.size() != 0) {
				return 1;
			}
			return 0;
		}

		int myans = 0;
		// include
		ans.add(arr[i]);
		myans += solverecursive(arr, i + 1, ans, k);
		ans.remove(ans.size() - 1);

		// not include
		myans += solverecursive(arr, i + 1, ans, k);
		return myans;

	}

	public static void solvedp(int[] arr, int k) {

		int[][] dp = new int[arr.length + 1][k + 1];

		for (int i = 1; i < dp.length; i++) 
    {
      
			for (int j = 1; j < dp[0].length; j++) 
      {
        // lets us run the loop 
				dp[i][j] = dp[i - 1][j];
				if (arr[i - 1] <= j && arr[i - 1] > 0) {
					dp[i][j] += dp[i - 1][j / arr[i - 1]] + 1;
				
        }
			
      }
		}

		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				
        System.out.print(dp[i][j] + " ");
			}
			System.out.println();
		}

	}
// ends the code
}
/*
=========================================================
 test cases
 Input:
arr[] = { 1, 2, 3, 4 }, K = 10 
Output: 
11 

{1}, {2}, {3}, {4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {1, 2, 3}, {1, 2, 4}
=========================================================  
*/
