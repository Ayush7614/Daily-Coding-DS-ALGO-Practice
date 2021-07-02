/*	Given an array of integers arr, return true if and only if it is a valid mountain array.

	Recall that arr is a mountain array if and only if:

    	arr.length >= 3
    	There exists some i with 0 < i < arr.length - 1 such that:
        	arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

		Example 1:

			Input: arr = [2,1]
			Output: false

		Example 2:

			Input: arr = [3,5,5]
			Output: false

		Example 3:

			Input: arr = [0,3,2,1]
			Output: true

 

		Constraints:

    			1 <= arr.length <= 104
    			0 <= arr[i] <= 104

 */
class ValidMountainArray{
    public boolean validMountainArray(int[] arr) {
	    //if the size of the array is less than 3 then it will return false
        if (arr.length < 3) return false;
        //if the 0-index of the array is greater than 1-index of the array then also it will return false because it will become right-slope
        if (arr[0] > arr[1]) return false;
        //if the size(arr)-2 of the array is greater than size(arr)-1 of the array then also it will return false because it will become left-slope
        if (arr[arr.length - 2] < arr[arr.length - 1]) return false;

        //this loop will iterate through arr.length if any index value is less than 0 it will return false because there is no value is present in them.
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) return false;
        }
        int upperSlope = 0;
        int lowerSlope = 0;

        //this loop will give the count of upperSlope
        for(int i = 0;i<arr.length-1;i++){
            if(arr[i] < arr[i+1]) upperSlope++;
            if(arr[i] > arr[i+1]) break;
        }
        //this loop will give the count of lowerSlope
        for(int i = 0;i<arr.length-1;i++){
            if(arr[i] > arr[i+1]) lowerSlope++;
        }
        //it will combine upperSlope and lowerSlope is equal to size of the array then it return true and it is a Valid mountain array
        return upperSlope + lowerSlope == arr.length-1;
    }
}