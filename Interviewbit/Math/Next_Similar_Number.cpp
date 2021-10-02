// https://www.interviewbit.com/problems/next-similar-number/
O(N) Time

string Solution::solve(string A) {
    
    int n = A.length(), i = n-1;
    
    for(  ; i > 0 ; i-- ){
         if( A[i] > A[i-1] )
            break;
    }
    
    if( i == 0)
        return "-1";
    
    int minn = i;
    for( int j = i+1 ; j < n ; j++){
        
        if( A[minn] > A[j] && A[j] > A[i-1])
            minn = j;
    }
    
    swap(A[i-1],A[minn]);
    sort(A.begin()+i, A.end());
    return A;
}
