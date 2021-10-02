// https://www.interviewbit.com/problems/find-duplicate-in-array/
// O(N) Solution O(N) Space

int Solution::repeatedNumber(const vector<int> &A) {
    
    bool arr[A.size()+1] ;
    
    for(int i = 0 ; i < A.size()+1 ; i++)
        arr[i] = false;
        
    for(int i = 0 ; i < A.size() ; i++){
        
        if( arr[A[i]] )
            return arr[A[i]];
        
        arr[A[i]] = true;
    }
    return -1;
}

