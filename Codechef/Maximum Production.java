import java.io.*;
import java.util.*;
 class MyClass {
    public static void main(String args[]) {
      Scanner sc=new Scanner(System.in);
      int t=sc.nextInt();
      for(int x1=1;x1<=t;x1++)
      {
          int d=sc.nextInt();
          int x=sc.nextInt();
         int y=sc.nextInt();
          int z=sc.nextInt();
          int ans=(y*d)+z*(7-d);
          System.out.println(Math.max(ans,(7*x)));      
      }
    }
}

// Sample Input
// 3
// 1 2 3 1
// 6 2 3 1
// 1 2 8 1
// Sample Output
// 14
// 19
// 14