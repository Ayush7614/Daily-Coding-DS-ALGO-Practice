import java.util.*;

class SortWave
{
    // method return the wave array
    public void sortInWave(int arr[], int n){

        for(int i =1 ;i < n; i+=2){
            swap(arr,i);
        }

    }
    //swap alternate elements of array.
    public void swap(int arr[], int i){
        int temp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i] = temp;
    }

    public static void main(String args[])
    {
        SortWave ob = new SortWave();
        Scanner sc = new Scanner(System.in);
        //Inputting Testcases
        int t = sc.nextInt();
        while(t-- > 0){
            //NOTE : In this question we've sorted array.
            //If the array is not sorted first sort the array, you can use Arrays.sort() function.

            //Input length of array
            int n = sc.nextInt();
            //array of length n.
            int arr[] = new int[n];
            //Input Array
            for(int i = 0 ; i < n; i++)
                arr[i] = sc.nextInt();

            ob.sortInWave(arr, n);

            for (int i : arr)
                System.out.print(i + " ");
        }
        sc.close();
    }
}
//Time Complexity : O(N)
//Space Complexity : O(1)

//Testcases : 

//Input:
// n = 5
// arr[] = {1,2,3,4,5}
// Output: 2 1 4 3 5
// Explanation: Array elements after 
// sorting it in wave form are 
// 2 1 4 3 5.

// Input:
// n = 6
// arr[] = {2,4,7,8,9,10}
// Output: 4 2 8 7 10 9
// Explanation: Array elements after 
// sorting it in wave form are 
// 4 2 8 7 10 9.