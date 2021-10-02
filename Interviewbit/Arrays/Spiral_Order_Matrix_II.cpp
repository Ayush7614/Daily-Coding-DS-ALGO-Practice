// https://www.interviewbit.com/problems/spiral-order-matrix-ii/
// 0(AXA) Solution

vector<vector<int> > Solution::generateMatrix(int A) {
    
    vector<vector<int> > ans(A,vector<int>(A,0));
    int l = 0 , r = A-1, u = 0 , d = A-1, count = 1 , s = 0;
    
    while( l <= r || u <= d){
        
        if( s == 0){
            
            for(int i = l ; i <= r ;i++){
                
                ans[u][i] = count;
                count++;
            }
            s = 1;
            u++;
        }
        
        if( s == 1){
            
            for(int i = u ; i <= d ;i++){
                
                ans[i][r] = count;
                count++;
            }
            s = 2;
            r--;
        }
        
        if( s == 2){
            
            for(int i = r ; i >= l ;i--){
                
                ans[d][i] = count;
                count++;
            }
            s = 3;
            d--;
        }
        
        if( s == 3){
            
            for(int i = d ; i >= u ;i--){
                
                ans[i][l] = count;
                count++;
            }
            s = 0;
            l++;
        }
    }
    return ans;
}
