// Java implementation of above approach
import java.io.*;

class GFG
{
	
static int N = 4;

// Function to rotate the matrix 90 degree clockwise
static void rotate90Clockwise(int a[][])
{

	// Traverse each cycle
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = i; j < N - i - 1; j++)
		{

			// Swap elements of each cycle
			// in clockwise direction
			int temp = a[i][j];
			a[i][j] = a[N - 1 - j][i];
			a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = temp;
		}
	}
}

// Function for print matrix
static void printMatrix(int arr[][])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		System.out.print( arr[i][j] + " ");
		System.out.println();
	}
}

// Driver code

	public static void main (String[] args)
	{
			int arr[][] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };
	rotate90Clockwise(arr);
	printMatrix(arr);
	}
}

// This code has been contributed by Bharat Tyagi

