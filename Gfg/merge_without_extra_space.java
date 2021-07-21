import java.util.*;
public class merge_without_extra_space {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < a.length; i++){
            a[i] = sc.nextInt();
        }
        int b[] = new int[m];
        for(int i = 0; i < b.length; i++){
            b[i] = sc.nextInt();
        }

        //This is swapping approach
        int k = n-1, j = 0;
        while(k >=0 && j <= m){
            if(a[k] > b[j]){
                int temp = a[k];
                a[k] = b[j];
                b[j] = temp;
            }
            k--;
            j++;
        }
        Arrays.sort(a);
        Arrays.sort(b);

        System.out.println("Sorted array is: ");
        for(int i = 0; i < a.length; i++){
            System.out.print(a[i]+" ");
        }
        for(int i = 0; i < b.length; i++){
            System.out.print(b[i]+" ");
        }
    }
    
}
/*test cases
Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}  

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}*/
