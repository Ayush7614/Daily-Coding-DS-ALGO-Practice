import java.util.*;
 class MyClass {
    public static void main(String args[]) {
     Scanner sc=new Scanner(System.in);
     int t=sc.nextInt();
     for(int y=1;y<=t;y++)
     {
         int n=sc.nextInt();
         ArrayList <Long> arr=new ArrayList<Long>();
         ArrayList <Long> arr1=new ArrayList<Long>();
         
         long a[]=new long[n];
         for(int x=0;x<n;x++)
         {
             a[x]=sc.nextLong();
             if(a[x]%2==0)
             {
                 arr.add(a[x]);
             }
             else{
                 arr1.add(a[x]);
             }
         }
         System.out.println(arr.toString().replace("[", "").replace("]", "").replace(",","")+" "+ arr1.toString().replace("[","").replace("]","").replace(",",""));
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
