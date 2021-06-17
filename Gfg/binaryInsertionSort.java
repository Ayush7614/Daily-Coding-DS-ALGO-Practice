
import java.util.Arrays;
class binaryInsertionSort
{

	public static void main(String[] args) {
		final int[] arr = { 37, 23, 6, 17, 12, 72, 31, 46, 120, 78, 59 };
		new binaryInsertionSort().sort(arr);
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
	}

	// Driver Code
	public void sort(int array[]) {
		for (int i = 1; i < array.length; i++) {
			int x = array[i];

			// using binary search
			int j = Math.abs(Arrays.binarySearch(array, 0, i, x) + 1);
			System.arraycopy(array, j, array, j + 1, i - j);
			array[j] = x;
		}
	}
}


// Output:
// 6 12 17 23 31 37 46 59 72 78 120 
