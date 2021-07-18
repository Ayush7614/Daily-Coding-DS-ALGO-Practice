package bitmasking;

public class missingtwonumber {
//let us start
	
	public static void main(String[] args)
  {
		// we need TODO Auto-generated method stub
		int[] arr = { 5, 4, 3 };
		missingno(5, arr);

	}

	public static void missingno(int n, int[] arr) {
// we are going to create a function to call the 2 missing numbers
		
		int z = 1;
		for (int i = 2; i <= n; i++) {
			z = z ^ i;
		}

		for (int i = 0; i < arr.length; i++) {
			z = z ^ arr[i];
		}

		// now z contains xor of two missing no
//		System.out.println(z);

		int rightmostsetbit = z & ~(z - 1);

		int set = 0, reset = 0;
		for (int i = 1; i <= n; i++) {
			if ((i & rightmostsetbit) != 0) {
				set = set ^ i;
			} else {
				reset = reset ^ i;
			}
		}
//creating another loop
		for (int i = 0; i < arr.length; i++) {
			if ((arr[i] & rightmostsetbit) != 0) {
				set = set ^ arr[i];
			} else {
				reset = reset ^ arr[i];
			}
		}
// and that is it. we are done 
		System.out.println("missing no are -> " + set + " , " + reset);

	}

}
/*
=====================================================
  INPUT
  {5,4,3}
output 
missing no are -> 1,2
===================================================== 
*/
