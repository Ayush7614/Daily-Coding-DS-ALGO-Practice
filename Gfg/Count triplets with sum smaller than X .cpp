// Problem Link : https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    long long count = 0;
	    for(int i = 0; i < n-2; i++){// this loop will select 1st element of triplet
	    //selecting other 2 elements of triplet
	        int j = i+1; 
	        int k = n-1;
	        while(j < k){
	            if(arr[i] + arr[j] + arr[k] >= sum){ // if our sum is grater ot equal to given sum then we will reducce it by doing k--
	                k--;
	            }else{ // if sum is less then given sum then we can select k-j elements as 3nd member and 2nd menber will be jth element and we will increment j to find next triplet
	                count += k-j;
	                j++;
	            }
	        }
	    }
	    return count;
	}
