package copyset;

public class copysetbits {
// let us start
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(copybits(13, 10, 2, 3));

	}
	// a -> b copy set bits in range
	public static int copybits(int a, int b, int l, int r) {
//defining m1
		int m1 = 1;
    
		m1 = m1 << (r - l + 1);
    //You have to set bits in B which are set in A lying in the above mentioned range.
		m1 = m1 - 1;
		m1 = m1 << (l - 1);
    
//Printing the updated number p.
		int actualmask = a & m1;
		return b | actualmask;

	}

}
