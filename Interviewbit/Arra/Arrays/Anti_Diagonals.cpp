// https://www.interviewbit.com/problems/anti-diagonals/
// O(N*N) Solution

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int n=A.size();
    if(n==0) return {};
    
    vector<vector<int>> v(2*n-1);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v[i+j].push_back(A[i][j]);
            
    return v;
}
