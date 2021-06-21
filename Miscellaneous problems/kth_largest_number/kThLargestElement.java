package Miscellaneous

//Find the k-th largest number in a sequence of unsorted numbers.
//


public class kThLargestElement {

    public int findKthSmallest(int[] arr, int n, int k)
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


}
