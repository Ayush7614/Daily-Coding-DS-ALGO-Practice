/* Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
Count the number of possible Binary Search Trees with n keys (See this)
Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
*/

class CatalnNumber {

	// A recursive function to find nth catalan number

	int catalan(int n)
	{
		int res = 0;

		// Base case
		if (n <= 1)
		{
			return 1;
		}
		for (int i = 0; i < n; i++)
		{
			res += catalan(i)
				* catalan(n - i - 1);
		}
		return res;
	}

	// Driver Code
	public static void main(String[] args)
	{
		CatalnNumber cn = new CatalnNumber();
		for (int i = 0; i < 10; i++)
		{
			System.out.print(cn.catalan(i) + " ");
		}
	}
}
