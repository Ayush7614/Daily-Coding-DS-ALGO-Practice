// problem link: https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays1618/1/?track=P100-Searching#


void merge(int arr1[], int arr2[], int n, int m) 
	{   
	    int temp;
	     int i=0,j=n-1;
	     
	    while(i < m && j >= 0)
	    {
	        if(arr1[j] > arr2[i])
	        {
	            swap(arr1[j], arr2[i]);
	        }
	        i++;
	        j--;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
    }
    int findMedian(int arr[], int n, int brr[], int m)
    { // based on basic definition of median
        merge(arr, brr, n, m); 
        if((n+m) % 2 == 0) // if total number of elements are even:
        { // median= (total elements - 1) + (total elements + 1)/2
          
            if(((n+m) / 2) + 1 <=n) return ((arr[(n+m)/2] + arr[(n+m)/2 - 1])/2); // if total-1 and total+1 both are less than n
            else if (((n+m) / 2) + 1 >n) return ((brr[(n+m)/2 -n] + brr[(n+m)/2 - 1-n])/2); // if total-1 and total+1 both are more than n
            else if((n+m)/2 == n) return (arr[n-1] + brr[0])/2; // if n==m
        }
        else // if total elements are odd:
        { // median = total elements/2
            if(((n+m) / 2) + 1 <=n) return arr[(n+m)/2];
            else return brr[(n+m)/2 - n];
        }        
    }
