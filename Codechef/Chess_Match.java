import java.util.*;
 class MyClass {
    public static void main(String args[]) {
      Scanner sc=new Scanner(System.in);
      int t=sc.nextInt();
      for(int x=1;x<=t;x++)
      {
          int a=sc.nextInt();
          int b=sc.nextInt();
          int c=sc.nextInt();
         int d=c+b;
         System.out.println((360+2*a)-d);
      }
     
    }
}


//  Input
// 3
// 10 0 2
// 11 2 1
// 12 192 192
//  Output
// 378
// 379
// 0