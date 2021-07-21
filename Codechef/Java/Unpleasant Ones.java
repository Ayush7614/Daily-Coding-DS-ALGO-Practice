import java.util.*;
 class MyClass {
    public static void main(String args[]) {
     Scanner sc=new Scanner(System.in);
     int t=sc.nextInt();
     for(int y=1;y<=t;y++)
     {
         int n=sc.nextInt();
         List<Long> b = new ArrayList<>();   
         List<Long> c = new ArrayList<>();   
         int i=0;int j=0;

         long a[]=new long[n];
         for(int x=0;x<n;x++)
         {
             a[x]=sc.nextLong();
             if(a[x]%2==0)
             {
                 b.add(a[x]);
             }
             else{
                 c.add(a[x]);
                 
             }
         }
         List<Long> finallist = new ArrayList<Long>(b);
         finallist.addAll(c);
          System.out.println(finallist.toString().replace("[", "").replace("]", "").replace(",",""));         
     }
    }
}
// Input
// 2   
// 3  
// 3 6 5  
// 2   
// 7 6
// Output
// 5 6 3  
// 6 7 