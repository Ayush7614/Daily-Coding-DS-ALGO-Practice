package recursionProblems;

public class DecreasingAndIncreasing {

	public static void main(String[] args) {
		int n=5;
		System.out.print("Decreasing Order is:");
		Decreasing(n);
		System.out.print("\nIncreasing Order is:");
		Increasing(n);
	}

	private static void Increasing(int n) {

		if(n==0)
		{
			return;
		}
		Increasing(n-1);
		System.out.print(n);
	}

	private static void Decreasing(int n) {
		if(n==0)
		{
			return;
		}
		System.out.print(n);
		Decreasing(n-1);
		
	}

}
