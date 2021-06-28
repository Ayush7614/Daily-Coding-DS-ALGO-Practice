import java.util.*;
class MyClass {
    public static void main(String args[]) {
      Scanner sc=new Scanner(System.in);
      int t=sc.nextInt();
      for(int y=1;y<=t;y++)
      {
          String c="";
          int flag=0;
          int counter=0;
          String s=sc.next();
          if(s.length()<4)
          {
               System.out.println("Error");
          }
          else{
          if(s.charAt(0)=='<' && s.charAt(1)=='/' && s.charAt(s.length()-1 )== '>')
          {
               for(int x=2;x<s.length()-1;x++)
          {
              char ch=s.charAt(x);
              if(((int)ch>=97 && (int)ch<=122) || ((int)ch>=48 && (int)ch<=57))
              {counter++;
              }else
              {flag=1;
              break;}
              
          }
          if(flag==0)
          {
              System.out.println("Success");
          }
          else
          { 
              System.out.println("Error");
          }}
           else
           { 
               System.out.println("Error");
         }}
          
      }
      
    }
}


// Input
// 5 
// </h1>  
// Clearly_Invalid  
// </singlabharat>  
// </5>  
// <//aA>  


// Output
// Success  
// Error  
// Success
// Success
// Error