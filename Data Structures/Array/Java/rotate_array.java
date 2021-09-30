package functions;
import java.io.*;

public class rotate_array {
	public static void display(int[] a){
	    StringBuilder sb = new StringBuilder();

	    for(int val: a){
	      sb.append(val + " ");
	    }
	    System.out.println(sb);
	  }
	 public static void reverse(int[] a, int m, int k){
	     for(int i=m;i<k;i++){
	         int temp=a[i];
	         a[i]=a[k];
	         a[k]=temp;
	         k--;
	     }
	 }
	 
	  public static void rotate(int[] a, int k){
	      k= k % a.length;
	      if(k<0){
	          k=k+a.length;
	      }
	    reverse(a,0,a.length-k-1);
	    reverse(a,a.length-k,a.length-1);
	    reverse(a,0,a.length-1);
	  }

	public static void main(String[] args) throws Exception  {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	    int n = Integer.parseInt(br.readLine());
	    int[] a = new int[n];
	    for(int i = 0; i < n; i++){
	       a[i] = Integer.parseInt(br.readLine());
	    }
	    int k = Integer.parseInt(br.readLine());

	    rotate(a, k);
	    display(a);

	}

}
