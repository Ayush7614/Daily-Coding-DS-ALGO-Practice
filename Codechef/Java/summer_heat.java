/*Summer Heat solution , codechef june long challenge Problem Code: COCONUT*/

import java.util.*;
import java.lang.*;
import java.io.*;

class summerheat
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();

		int arr[] = new int[t];

		for(int i=0; i<t; i++){
			int xa = in.nextInt();
			int xb = in.nextInt();
			int Xa = in.nextInt();
			int Xb = in.nextInt();

			int  a = Xa/xa;
			int b = Xb/xb;

			int sum = a + b;
			arr[i] = sum;
		}

		for(int i=0; i<t; i++){
			System.out.println(arr[i]);
		}
	}
}
