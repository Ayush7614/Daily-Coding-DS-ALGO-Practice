import java.io.*;
import java.util.*;

public class Main{
// display the contents of array
  public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + " ");
    }
    System.out.println(sb);
  }

  // reverse the content of array
public static void reverse(int[] a,int li,int ri){
   
    while(li < ri){
      int temp = a[li];
      a[li]= a[ri];
      a[ri] = temp;
      li++;
      ri--;
    }
}

  // function to rotate the array by a number k
  public static void rotate(int[] a, int k){
    int  n=a.length;
    // if k>length of array
    k=k%n ;
    // if k is negative 
    if(k<0)
    k+=n ;

    reverse(a,0,n-1) ;
    reverse(a,0,k-1) ;
    reverse(a,k,n-1) ;
  }

// main function to take input of array elements and a number k
public static void main(String[] args) throws Exception {
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