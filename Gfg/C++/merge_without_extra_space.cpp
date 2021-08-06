// Problem link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
// two pointer approach 
// without using any extra space, we store smaller elements in 1st array and rest in 2nd array
void merge(int arr1[], int arr2[], int n, int m) 
	{                     // slightly modified two pointer approach where one pointer is pointing to staring of one array and 
	     int i=0,j=n-1;   // and another pointer pointing to last element of second array
	    while(i < m && j >= 0) // we continue checking until with reach the end of any of the 2 arrays
	    {
	        if(arr1[j] > arr2[i]) // comparing both the arrays and checking if element of 1st array is larger in comparision to other
	        {
	            swap(arr1[j], arr2[i]); // if element of 1st array is greater then we swap so as to get all smaller elements in 1st array
	        }
	        i++; // moving the two pointers furthur
	        j--;
	    }
	    sort(arr1,arr1+n); // Swapping may result in unorederd elements so finaaly sorting them
	    sort(arr2,arr2+m);
}
