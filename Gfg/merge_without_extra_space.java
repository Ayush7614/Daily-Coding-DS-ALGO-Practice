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
