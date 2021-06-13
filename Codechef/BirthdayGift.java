/*Java solution for codechef question Birthday Gifts  Problem code: TWINGFT  
link for problem statement https://www.codechef.com/LTIME96C/problems/TWINGFT */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class BirthdayGift
{
 public static void main (String[] args) throws java.lang.Exception
 {
  // your code goes here
  Scanner sc=new Scanner(System.in);
  int t=sc.nextInt();
  while(t-- > 0){
      int n=sc.nextInt();
      int k=sc.nextInt();
      int[] a=new int[n];
      for(int i=0;i<n;i++){
          a[i]=sc.nextInt();
      }
      Arrays.sort(a);
      long s1=0;
      long s2=0;
      int i=n-1;
      while(k-- > 0){

          s1=s1+(long)(a[i]);
          s2=s2+(long)(a[i-1]);
          i=i-2;
      }
      s2=s2+(long)(a[i]);
      System.out.println((s1>s2)?s1:s2);

  }
 }
}
