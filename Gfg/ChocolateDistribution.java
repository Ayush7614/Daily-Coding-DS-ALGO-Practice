import java.util.*;

public class ChocolateDistribution {
    public static void main (String[] args) throws java.lang.Exception{
        Scanner sc  = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        int i=0, j=m-1;
        int min = Integer.MAX_VALUE;
        while(j<n)
        {
            if((arr[j]-arr[i])<min)
            {
                min=arr[j]-arr[i];
            }
            i++;
            j++;
        }
        System.out.println(min);
    }
}