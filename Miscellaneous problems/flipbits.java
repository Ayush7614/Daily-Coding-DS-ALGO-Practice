package hi;

public class counting_flipbits {

	public static void main(String[] args) {
		//we need TODO Auto-generated method stub

	}

	public static int countBitsFlip(int a, int b) {
// we are creating a function
		int z = a ^ b;
		int c = 0;
		while (z != 0) {
			c++;
			z = z & (z - 1);
		}

		return c;
	}
}
/*
=================================================

Input : a = 7, b = 10
Output : 3
  
=================================================  
*/
