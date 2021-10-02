https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
0(A) solution

vector<int> Solution::getRow(int A) {
    
    vector<vector<int> > ans(A+1);
    
    for(int i = 0 ; i <= A ; i++)
        ans[i] = vector<int>(i+1,1);
      
    for(int i =2 ; i <= A ; i++){
        for(int j = 1 ; j < ans[i].size()-1 ; j++)
            ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
    }
    return ans[A];
}
