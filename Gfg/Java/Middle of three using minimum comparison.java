// Question  https://www.geeksforgeeks.org/middle-of-three-using-minimum-comparisons/

// Example 1
// Input : a = 20, b = 30, c = 40
// Output : 30

// Example 2
// Input : a = 12, n = 32, c = 11
// Output : 12

// Solution

import java.util.*;

class Middle
{
	public static int middleOfThree(int a, int b, int c)
	{
		int x = a - b;
		int y = b - c;
		int z = a - c;

		if (x * y > 0)
			return b;

		else if (x * z > 0)
			return c;
		else
			return a;
	}
	
	public static void main(String[] args)
	{
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        System.out.println( middleOfThree(a, b, c) );
	}
}