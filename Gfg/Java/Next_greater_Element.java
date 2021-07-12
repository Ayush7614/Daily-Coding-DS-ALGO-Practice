import java.util.*;
public class Next_greater_Element{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt(); //testCases
        while(t-->0){
        int n=sc.nextInt(); //size of array
        long a[]=new long[n]; //creating array of size
        for(int i=0;i<n;i++) a[i]=sc.nextLong(); //taking input from user
        Sol s=new Sol();
        long ans[]=s.nextLargerElement(a,n);
        for(int i=0;i<n;i++)
        {
            System.out.print(ans[i]+" ");
        }
        System.out.println();
        }

    }
}
class Sol
{
    //Function to find the next greater element for each element of the array.
    public static long[] nextLargerElement(long[] arr, int n)
    {
        // Your code here
        long a[]=new long[n];
       a[n-1]=-1; //since NGE of last element is always -1 so assigning -1 to last element as its NGE
       Stack<Long> st=new Stack<>();
       for(int i=n-1;i>=0;i--) //loop from last
       {
           if(!st.isEmpty())
           {
            //popping element fom stack until element in the stack is smaller than current element arr[i]
            while(!st.isEmpty() && (st.peek()<=arr[i])) st.pop();

           }
            a[i]=st.isEmpty()?-1:st.peek(); //check if stack is empty means there is no NGE of current elemnt else
            //element at the top of stack is NGE of current element
           st.push(arr[i]); //pushong current elemnt in the stack
       }

       return a;
    }

}
//Time Compelxity-> O(n) ,n->size of array
//Space Complexity-O(n)
/*----------------------------------------OUTPUT---------------------------------*/
//t=1
//N = 5, arr[] [6 8 0 1 3]
//Result-> [8,-1,1,3,-1]
