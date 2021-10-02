// https://www.interviewbit.com/problems/maximum-unsorted-subarray/
// O(N) Time O(1) Space

vector<int> Solution::subUnsort(vector<int> &A) {
    
    int i = 0, j = A.size()-1;
    for( i = 0 ; i < A.size() ; i++){
        
        if( i < A.size()-1 && A[i] > A[i+1])
            break;
    }
    
    if( i == A.size())
        return {-1};
        
    for( ; j >= 0 ; j--){
        
        if( j -1 >= 0 && A[j] < A[j-1])
            break;
    }
    
    int ans1 = A[i], ans2 = A[j];
    
    for(int k = i ; k <= j ; k++){
        
        ans1 = min(ans1,A[k]);
        ans2 = max(ans2,A[k]);
    }
    int m = 0, n = A.size()-1;
    for(; m < i ; m++){
        
        if( A[m] > ans1)
            break;
    }
    
    for(; n > j ; n--){
        
        if(A[n] < ans2)
            break;
    }
    return {m,n};
}
