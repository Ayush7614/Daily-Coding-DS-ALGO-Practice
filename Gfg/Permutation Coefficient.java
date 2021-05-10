// Java code for Dynamic Programming based
// solution that uses table P[][] to
// calculate the Permutation Coefficient
import java.io.*;
import java.math.*;

class GFG
{
	
	// Returns value of Permutation
	// Coefficient P(n, k)
	static int permutationCoeff(int n,
								int k)
	{
		int P[][] = new int[n + 2][k + 2];
	
		// Calculate value of Permutation
		// Coefficient in bottom up manner
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0;
				j <= Math.min(i, k);
				j++)
			{
				// Base Cases
				if (j == 0)
					P[i][j] = 1;
	
				// Calculate value using previosly
				// stored values
				else
					P[i][j] = P[i - 1][j] +
							(j * P[i - 1][j - 1]);
	
				// This step is important
				// as P(i,j)=0 for j>i
				P[i][j + 1] = 0;
			}
		}
		return P[n][k];
	}
	
	// Driver Code
	public static void main(String args[])
	{
		int n = 10, k = 2;
		System.out.println("Value of P( " + n + ","+ k +")" +
						" is " + permutationCoeff(n, k) );
	}
}

// This code is contributed by Nikita Tiwari.
// Java code for Dynamic Programming based
// solution that uses table P[][] to
// calculate the Permutation Coefficient
import java.io.*;
import java.math.*;

class GFG
{
	
	// Returns value of Permutation
	// Coefficient P(n, k)
	static int permutationCoeff(int n,
								int k)
	{
		int P[][] = new int[n + 2][k + 2];
	
		// Calculate value of Permutation
		// Coefficient in bottom up manner
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0;
				j <= Math.min(i, k);
				j++)
			{
				// Base Cases
				if (j == 0)
					P[i][j] = 1;
	
				// Calculate value using previosly
				// stored values
				else
					P[i][j] = P[i - 1][j] +
							(j * P[i - 1][j - 1]);
	
				// This step is important
				// as P(i,j)=0 for j>i
				P[i][j + 1] = 0;
			}
		}
		return P[n][k];
	}
	
	// Driver Code
	public static void main(String args[])
	{
		int n = 10, k = 2;
		System.out.println("Value of P( " + n + ","+ k +")" +
						" is " + permutationCoeff(n, k) );
	}
}

// This code is contributed by Nikita Tiwari.
