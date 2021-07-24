// Java program to check if
// three points are collinear
// or not using area of triangle.
class GFG
{
	
	// function to check if
	// point collinear or not
	static void collinear(int x1, int y1, int x2,
						int y2, int x3, int y3)
	{
		
		/* Calculation the area of
		triangle. We have skipped
		multiplication with 0.5
		to avoid floating point
		computations */
		int a = x1 * (y2 - y3) +
				x2 * (y3 - y1) +
				x3 * (y1 - y2);
	
		if (a == 0)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
		
	// Driver Code
	public static void main(String args[])
	{
		int x1 = 1, x2 = 1, x3 = 1,
			y1 = 1, y2 = 4, y3 = 5;
							
		collinear(x1, y1, x2, y2, x3, y3);

	}
}

// This code is contributed by Ayan.
