package Miscellaneous

//Find the k-th largest number in a sequence of unsorted numbers.
 
// Input:

// [8, 7, 2, 3, 4, 1, 5, 6, 9, 0], K = 3

// Output:

// 7

// PRograming Language Java


public class kThLargestElement {

    public int findkThLargestElement(int[] arr, int n, int k)
    {

        int max = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }


        int[] counter = new int[max + 1];

        int smallest = 0;

        for (int i = 0; i < n; i++)
        {
            counter[arr[i]]++;
        }

        for (int num = 1; num <= max; num++)
        {

            if (counter[num] > 0)
            {

                smallest += counter[num];
            }

            if (smallest >= k)
            {

                return num;
            }
        }
        return -1;
    }
    
        public static void main(String[] args)
    {
        // Given array
        int[] arr = { 7, 1, 4, 4, 20, 15, 8 };
 
        int N = arr.length;
 
        int K = 5;
 

        System.out.print(findkThLargestElement(arr, N, K));
    }
    
    


}
