package com.tirth;
import java.util.Vector;

public class Main {
    public static void insertion_sort(Vector<Float> Array)
    {
        for(int k=1; k < Array.size() - 1; k++){
            float temp = Array.get (k);
            int j= k-1;

            while(j>=0 && temp <= Array.get (j) ){
                Array.set (j + 1, Array.get (j));
                j = j-1;
            }

            Array.set (j + 1, temp);
        }
    }
    public static void bucket_sort(float[] array, int n)
    {
        int index_final;
        float  index_init;
        if (n <= 0) {
            return;
        }

        Vector<Float>[] buckets = new Vector[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new Vector<> ();
        }

        for (int i = 0; i < n; i++) {
            index_init = array[i] * n;
            buckets[(int) index_init].add(array[i]);
        }

        for (int i = 0; i < n; i++) {
            insertion_sort (buckets[i]);
        }

        index_final = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                array[index_final++] = buckets[i].get(j);
            }
        }
    }

    public static void main (String[] args) {
        float[] arr = { (float)0.123, (float)0.231, (float)0.18987, (float)0.9745, (float)0.569, (float)0.4848, (float)0.23 };

        int n = arr.length;
        bucket_sort (arr, n);

        System.out.println("Sorted array is ");
        for (float el : arr) {
            System.out.print(el + " ");
        }

    }
}


/*
Output ->

Sorted array is
0.123 0.18987 0.231 0.23 0.569 0.4848 0.9745
 */