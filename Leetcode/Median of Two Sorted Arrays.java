import java.util.*;
public class MyClass {
    // main function
    public static void main(String args[]) {
    Scanner sc=new Scanner(System.in);
    int m=sc.nextInt();
    int n=sc.nextInt();
    int a[]=new int[m];
    int b[]=new int[n];
    for(int x=0;x<m;x++)
    {
         a[x]=sc.nextInt();
    }
    for(int y=0;y<n;y++)
    {
         b[y]=sc.nextInt();
    }
    MyClass obj = new MyClass();
    double f=obj.findMedianSortedArrays(a,b);
    System.out.println(f);
    }

    public double findMedianSortedArrays(int[] input1, int[] input2) {
         if (input1.length > input2.length) {
            return findMedianSortedArrays(input2, input1);
        }
        int x = input1.length;
        int y = input2.length;

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;
            int maxLeftX = (partitionX == 0) ? Integer.MIN_VALUE : input1[partitionX - 1];
            int minRightX = (partitionX == x) ? Integer.MAX_VALUE : input1[partitionX];
            int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : input2[partitionY - 1];
            int minRightY = (partitionY == y) ? Integer.MAX_VALUE : input2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return ((double)Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2;
                } else {
                    return (double)Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else { 
                low = partitionX + 1;
            }
        }

        //Only we we can come here is if input arrays were not sorted. Throw in that scenario.
        throw new IllegalArgumentException();
    }
}


// Input 1
// 2 1
// 1 3
// 2
// Output 1
// 2.0

// Input 2
// 2 2
// 1 2
// 3 4
// Output 2
// 2.5