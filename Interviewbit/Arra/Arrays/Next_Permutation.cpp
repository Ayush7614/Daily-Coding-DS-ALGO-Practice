// https://www.interviewbit.com/problems/next-permutation/
// O(N) Solution

vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int i = 0;
    for( i = A.size()-1 ; i > 0 ; i--){
        if(  A[i] > A[i-1] )
            break;
    }
  
    if( i == 0){
        sort(A.begin(),A.end());
        return A;
    }
    
    int max = i;
    for( int k = i+1 ; k < A.size()-1 ; k++){
        if( A[i-1] < A[k] && A[max]  A[k] )
            max = k;
    }
    
    swap(A[i-1],A[max]);
    sort(A.begin()+i, A.end());
    
    return A;
}
