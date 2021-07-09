import java.io.*;
import java.util.*;
 class MyClass {
    public static void main(String args[])throws Exception {    
    Scanner sc=new Scanner(System.in);
    BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
     int t=sc.nextInt();
     for(int y=1;y<=t;y++)
     {
         long a=sc.nextLong();
         long b=sc.nextLong();
         if( (b & b-1) == 0)
         {
               output.write("YES\n");
               
         }
         else{
               output.write("NO\n");
         }   
     }
     output.flush();
    }
}

// Input
// 2
// 1 2
// 2 3

// Output
// Yes
// No