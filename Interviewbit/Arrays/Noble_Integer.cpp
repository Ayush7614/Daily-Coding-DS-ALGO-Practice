// https://www.interviewbit.com/problems/noble-integer/
// O(NlogN) Time  0(1) Solution

int Solution::solve(vector<int> &A) {
    int n=A.size();
    if(n==0)
        return -1;
        
    sort(A.begin(),A.end());
    
    if(A[n-1]==0)
        return 1;
        
    for(int i=0;i<n;i++){
        if(A[n-i-1]==i && A[n-i]>i)
            return 1;
    }
    return -1;
}
