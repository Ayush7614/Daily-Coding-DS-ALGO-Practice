package bitmasking;

public class printsubsets {
//let's start
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = { 1, 2, 3, 4 };
		subsets(arr);

	}

	public static void subsets(int[] arr) {
		int limit = (int) (1 << arr.length);
		for (int i = 0; i < limit; i++) {
			String set = "";
			int temp = i;
      
      //writing a for loop 
			for (int j = arr.length - 1; j >= 0; j--) {
				if ((temp & 1) == 1) {
					set = arr[j] + set;
				} else {
					set = " _ " + set;
				}
        // this will confirm the subset
				temp = temp >> 1;
			}
      //print the set
			System.out.println(set);
		}

	}

}

/*


Input: 
1 2
Output: 

         1 
         2
         1 2
         
         */
