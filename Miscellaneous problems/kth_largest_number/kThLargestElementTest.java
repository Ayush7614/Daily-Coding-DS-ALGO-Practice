package Miscellaneous

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.assertEquals;

class kThLargestElementTest {

    private final kThLargestElement kThLargestElement = new kThLargestElement();


    @Test
    void test1() {

        int[] arr = { 7, 1, 4, 4, 20, 15, 8 };

        int N = arr.length;

        int K = 5;
       assertEquals(8,kThLargestElement.findKthSmallest(arr,N,K));
    }
}