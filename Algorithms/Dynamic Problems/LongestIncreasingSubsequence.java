import java.util.*;
public class LongestIncreasingSubsequence {
public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    while(t-->0){
        int n=sc.nextInt(); //input the size of array
        int a[]=new int[n]; //array of size n
        for(int i=0;i<n;i++) a[i]=sc.nextInt(); //input array elements
        LIS ls=new LIS();
        System.out.println(ls.lis(a,n));


    }
}
}
class LIS{
    public static int lis(int a[],int n) //function that ill return length of longest increasing subsequence
    {
        int max_len=0; //it will store value of LIS
        int dp[]=new int[n]; //it will help to keep track fo previous LIS
        dp[0]=1; //since LIS for array of size 1 is 1
        for(int i=1;i<n;i++)
        {
            dp[i]=1; //since LIS for array of size 1 is 1
            for(int j=0;j<i;j++) //this will help to check all previous elements on left of a[i] which are less than it
            {
                if(a[j]<a[i]) //check if element on left of array is smaller than a[i];
                dp[i]=Math.max(dp[i],dp[j]+1); //stores maximum of value present at dp[i] or dp[j]+1
            //dp[j]->if at any index less than i value of LIS is greater than dp[i](current index) then update dp[i] with value of dp[j]+1.
            //added 1 to include the current index element of array a
            }
            max_len=Math.max(max_len,dp[i]); //updating max_len
        }
        return max_len;
    }
}
//Time Complexity->O(n*n)
//space complexity->O(n) //for dp array
/*--------------------------------------------RESULT------------------------- */
/*Input
t=2
test case-1:
n=8
a[]=[10,9,2,5,3,7,101,18]
Output-> 4
LIS->[2,3,7,101] o [2,5,7,101],
 test cae 2:
 n=5
 a[]=[5,5,5,5,5]
 output-> 1
 LIS->[5]
 */
public class LongestIncreasingSubsequnece {
    
}
