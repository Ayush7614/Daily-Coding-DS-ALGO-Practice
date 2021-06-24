/*Test Case 1:
Input : n = 5, a[] = {3, 2, 7, 6, 1} , m = 3
Output: Minimum difference is 2 

Test Case 2:
Input : n = 7, a[] = {8, 5, 6, 3, 2, 7, 1} , m = 5
Output: Minimum difference is 5


*/



import java.util.*;
class ChocolateDistribution {
    static int Min( int n,int a[],int m)
    {
        if (m == 0 || n == 0)
            return 0;
        Arrays.sort(a);
        if (n < m)
           return -1;
        int min = Integer.MAX_VALUE;
         
        for (int i = 0; i + m - 1 < n; i++)
        {
            int diff = a[i+m-1] - a[i];
            if (diff < min)
                min = diff;
        }
        return min;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n  = sc.nextInt();
        int a[] = new int[n];
        for(int i=0; i<n; i++)
        {
            a[i] = sc.nextInt();
        }
        int m = sc.nextInt();
        System.out.println("Minimum difference is "
                + Min(n,a,m));
             
    }
}
