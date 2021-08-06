import java.util.*;
class Main {
    public static void main(String args[])
	{
	    Scanner in = new Scanner(System.in);
	    System.out.println("Enter pieces: ");
	    int size = in.nextInt();
	    System.out.println("Enter price: ");
		int arr[] = new int[size];
		for(int i=0;i<size; i++)
		{
		    arr[i] = in.nextInt();
		}
		System.out.println("Maximum Obtainable Value is " + rodcut(arr, size));
	}
	static int rodcut(int price[], int n)
	{
		if (n <= 0)
			return 0;
		int max = Integer.MIN_VALUE;

		for (int i = 0; i < n; i++)
			max = Math.max(max,	price[i] + rodcut(price, n - i - 1));

		return max;
	}
}


/*Input : 
Enter pieces: 
8
Enter price:
1   5   8   9  10  17  17  20
output: 
Maximum Obtainable Value is 22
*/
