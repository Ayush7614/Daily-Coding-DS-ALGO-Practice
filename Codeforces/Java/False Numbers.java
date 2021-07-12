import java.util.*;
class MyClass {
    public static void main(String args[]) {
      Scanner sc=new Scanner(System.in);
      int t=sc.nextInt();
      for(int x=1;x<=t;x++)
      {
          String c="";
          String s=sc.next();
          if(s.charAt(0)=='1')
          {
              c=s.charAt(0)+"0"+s.substring(1);
          }
          else
          {
               c="1"+s.substring(0);
          }
          System.out.println(c);
          
      }
      
    }
}

// Input
// 2
// 9876543211
// 12345678999
// Output
// 19876543211
// 102345678999