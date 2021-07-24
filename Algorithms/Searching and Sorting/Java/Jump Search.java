// Jump search

import java.util.*;

class Main
{
static int jump_Search(int a[], int n, int item) 
{
   int i = 0;
   int m = (int)Math.sqrt(n); //initializing block size= √(n)
   while(a[m] <= item && m < n) 
   { 
      // the control will continue to jump the blocks 
      i = m;         // shift the block
      m = m + (int)Math.sqrt(n);
      if(m > n - 1)  // if m exceeds the array size
          m = n; 
   }

   for(int x = i; x<m; x++) { //linear search in current block
      if(a[x] == item)
         return x; //position of element being searched 
   }
   return -1;
}

public static void main(String args[]) 
{
   int n, item, loc;
   System.out.println("\n Enter number of items: ");
   Scanner sc = new Scanner(System.in);
   n = sc.nextInt();
   int arr[] = new int[n];              //creating an array of size n
   System.out.println( "\n Enter items: ");

   for(int i = 0; i<n; i++) 
   {
       arr[i] = sc.nextInt();
   }

   System.out.println("\n Enter search key to be found in the array: ");
    item = sc.nextInt();
    loc = jump_Search(arr, n, item);
   if(loc>=0)
      System.out.println(" Item found at location: " + loc);
   else
     System.out.println(" Item is not found in the list.");
  }
}
/* 
Input :- 
        3 
        1 2 3
        2
Output :- Item found at location:- 1
*/

/*
Time Complexity :- O(sqrt(n))
*/
