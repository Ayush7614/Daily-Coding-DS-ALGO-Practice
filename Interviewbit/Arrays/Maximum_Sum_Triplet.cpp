// https://www.interviewbit.com/problems/maximum-sum-triplet/
// video for explanation-  https://www.youtube.com/watch?v=l_hPdol4CSU 
// O(NLogN) Time O(N) Space

// iterate for every j
// create a suffix array for kth element
// sort and find max but < A[j] in range 0-j


int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    int left[n], right[n];
    left[0] = A[0], right[n-1] = A[n-1];
    set<int> st;
    st.insert(A[0]);
    
    // creating suffix array
    for( int i = n-2 ; i >= 0 ; i--)
        right[i] = max(A[i],right[i+1]);
        
    // storing max value < A[j] i range 0-j
    for( int i = 1; i < n ; i++){
        
        st.insert(A[i]);
        auto it = st.find(A[i]);
        
        if( it != st.begin()){
            --it;
            left[i] = *it;
        }
        else
            left[i] = A[i];
    }
    
    int ans = INT_MIN;
    // iterating through array for j
    for( int j = 1 ; j < n-1 ; j++){
        
        if( right[j] != A[j] && left[j] != A[j] )
            ans = max( ans, left[j]+A[j]+right[j]);
    }
    
    if( ans == INT_MIN)
        return 0;
    
    return ans;
}

