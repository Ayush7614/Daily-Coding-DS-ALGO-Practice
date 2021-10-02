// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
// Kaden's Algorithm
//O(N) solution

int Solution::maxSubArray(const vector<int> &A) {
    
    int sum = INT_MIN, temp_sum = 0;
    
    for( int i = 0 ; i < A.size() ; i++){
        
        temp_sum += A[i];
        sum = max(temp_sum,sum);
        
        if( temp_sum <= 0)
            temp_sum = 0;
    }
    return sum;
}
