// https://www.interviewbit.com/problems/leaders-in-an-array/
// O(N) Time O(1) Space

vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> ans;
    int n = A.size(), max_till_now = A[n-1];
    ans.push_back(A[n-1]);
    
    for( int i = n-1; i >= 0 ; i--){
        
        if( A[i] > max_till_now){
            
            ans.push_back( A[i]);
            max_till_now = A[i];
        }
    }
    return ans;
}
