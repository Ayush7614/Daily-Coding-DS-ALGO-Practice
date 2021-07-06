import java.util.Scanner;
public class sort012 {
    public class sorting
     {
         public void sort()
         {
        Scanner sc=new Scanner(System.in);
                System.out.println("enter the size of the array which just conist of 0,1,2");
                int n= sc.nextInt();
                int []arr=new int[n];
                for(int l=0;l<n;l++)
                {
                    arr[l]=sc.nextInt();
                }
    
                // code here
                int i = 0;
                int j = 0;
                int k = arr.length - 1;
                while (i <= k)
                {
                    if (arr[i] == 0) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                        i++;
                        j++;
    
                    } else if (arr[i] == 1) {
                        i++;
                    } else {
                        int temp = arr[i];
                        arr[i] = arr[k];
                        arr[k] = temp;
                        k--;
                    }
                }
                for(int r=0;r<n;r++)
                {
                    System.out.println(arr[r]);
                }
            }
        }
    
        
    }
   