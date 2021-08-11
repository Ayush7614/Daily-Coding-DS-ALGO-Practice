import java.util.*;

class xor
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            int n = sc.nextInt();
            int arr[] = new int[n];
            arr[0]=sc.nextInt();
            int min = arr[0];
            for(int i =1;i<n;i++)
            {
                arr[i]=sc.nextInt();
                if(arr[i]<min)
                min = arr[i];
            }
            int orr=0;
            for(int i=0;i<n;i++)
            {
                arr[i] ^= min;
                orr |= arr[i];
            }
            System.out.println(min+" "+orr);
        }
    }
}