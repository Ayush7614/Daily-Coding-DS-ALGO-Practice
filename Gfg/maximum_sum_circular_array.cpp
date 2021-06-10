// problem link: https://leetcode.com/problems/maximum-sum-circular-subarray/
// based on kadane's algorithm
// kadane's algorithm is used to find maximum sum subarray
// we can slightly modify kadane's algo and can use the same for circular subarray
// we have 2 possiblities: 1.  _ * * * _ _  maximum is present as a normal subarray (simple kadane's)
//                         2.  * _ _ * * *  maximum subarray is a circular subarray (modified kadane's by using a trick)
// trick for modified kadane's: for possiblity "2": maximum circular subarray sum is always equal to total sum- min norma subarray sum
// ie., in the 2nd example elements denoted by "_" are minimum circular subarray sum 
int maxSubarraySumCircular(vector<int>& arr) {
    int n=arr.size();
    int total=0;
	
    int circular_best=0,circular_sum=0,normal_best=0,normal_sum=0,check=0,maximum=arr[0];
    for(int j=0; j<n; j++)
    {
        if(arr[j] > 0) check=1;
        
        total+=arr[j];
        normal_sum=max(arr[j],arr[j]+normal_sum); // normal kadane's algo for possiblity 1
        normal_best=max(normal_sum,normal_best);
        circular_sum=min(arr[j],arr[j]+circular_sum); // modified kadane's algo for possiblity 2
        circular_best=min(circular_best,circular_sum); // maximum circular subarray sum = total sum- minimum circular subarray sum
        if(arr[j] > maximum) maximum=arr[j];
    }
    if(check == 0) return maximum;
    return max(total-circular_best,normal_best); // Checking for the best among possiblites 1 and 2 ie., best from normal sum and circular sum
    }
