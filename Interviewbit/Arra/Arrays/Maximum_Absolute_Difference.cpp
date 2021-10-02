// https://www.interviewbit.com/problems/maximum-absolute-difference/
// Open the mod
// O(N) Solution

int Solution::maxArr(vector<int> &A) {
    
    int a = INT_MIN , b = INT_MAX, c = INT_MAX , d = INT_MIN;
    // a = max(A[i]+i) in array, b = min of (A[i]+i) in array, c = max(A[i]-i) in array, d = min of (A[i]-i) in array
    
    for( int i = 0 ; i < A.size() ; i++){
        
        if( A[i]+i > a)
            a = A[i]+i;
            
        if( A[i] + i < b)
            b = A[i]+i;
        
        if( A[i]-i < c)
            c = A[i]-i;
            
        if( A[i]-i > d)
            d = A[i]-i;
    }
    return max(a-b, d-c);
}
