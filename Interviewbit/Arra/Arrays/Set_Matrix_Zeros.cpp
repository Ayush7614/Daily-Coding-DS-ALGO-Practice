// https://www.interviewbit.com/problems/set-matrix-zeros/
0(N*M) Solution

void Solution::setZeroes(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    bool row = false, col = false;
    
    // checking if 1st column needs to be 0 or not
    for( int i = 0 ; i < n ; i++){
        
        if( A[i][0] == 0){
            col = true;
            break;
        }
    }
    // checking if 1st row needs to be 0 or not
    for( int i = 0 ; i < m ; i++){
        
        if( A[0][i] == 0){
            row = true;
            break;
        }
    }
    // storing which row and column of matrix needs to be 0in 1st row and 1 column
    for( int i = 1; i < n ; i++){
        for( int j = 1 ; j < m ; j++){
            
            if( A[i][j] == 0){
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }
    // coverting corresponding rows and columns to zero
    for( int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            
            if( A[i][0] == 0 || A[0][j] == 0)
                A[i][j] = 0;
        }
    }
    
    // setting first row to 0 if required
    if(row){
        for( int i = 0 ; i < m ; i++)
            A[0][i] = 0;
    }
    
    // setting first col to 0 if required
    if(col){
        for( int i = 0 ; i < n ; i++)
            A[i][0] = 0;
    }
}
