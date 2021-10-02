// https://www.interviewbit.com/problems/wave-array/
// O(NlogN) Time 

vector<int> Solution::wave(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    for( int i = 0 ; i < A.size() ; i = i+2){
        
        if( i < A.size()-1)
            swap(A[i],A[i+1]);
    }
    return A;
}
