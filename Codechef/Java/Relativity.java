import java.io.*;
import java.util.*;
 class MyClass {
    public static void main(String args[]) {
      Scanner sc=new Scanner(System.in);
      int t=sc.nextInt();
      for(int x1=1;x1<=t;x1++)
      {
          int g=sc.nextInt();
          int c=sc.nextInt();
          int ans=(c*c)/(2*g);
          System.out.println(ans);    
      }
    }
}
// Sample Input
// 3
// 7 1400
// 5 1000
// 10 1000
// Sample Output
// 140000
// 100000
// 50000