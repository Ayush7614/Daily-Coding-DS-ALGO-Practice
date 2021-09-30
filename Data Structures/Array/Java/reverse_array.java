package functions;
import java.io.*;

public class reverse_array {
	public static void display(int[] a){
	    StringBuilder sb = new StringBuilder();

	    for(int val: a){
	      sb.append(val + " ");
	    }
	    System.out.println(sb);
	  }
	 public static void reverse(int[] a){
		    int end=a.length-1;
		    for(int i=0;i<end;i++){
		        int temp=a[i];
		        a[i]=a[end];
		        a[end]=temp;
		        end--;
		    }
		  }

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	    int n = Integer.parseInt(br.readLine());
	    int[] a = new int[n];
	    for(int i = 0; i < n; i++){
	       a[i] = Integer.parseInt(br.readLine());
	    }

	    reverse(a);
	    display(a);

	}

}
