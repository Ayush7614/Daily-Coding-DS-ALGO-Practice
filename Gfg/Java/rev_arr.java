import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
	Scanner sc=new Scanner(System.in);
 int t=sc.nextInt();
 
 while(t>0)
 {
     
     int n=sc.nextInt();
     int arr[]=new int[n];
     for(int i=0;i<n;i++)
     {
         arr[i]=sc.nextInt();
     }
     for(int i=n-1;i>=0;i--)
     {
         System.out.print(arr[i]+" ");
     }
     t--;
     System.out.println();
 }
}
}
