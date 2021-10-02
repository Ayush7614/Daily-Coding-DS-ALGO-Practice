// https://www.interviewbit.com/problems/minimum-lights-to-activate/
O(N) solution

int Solution::solve(vector<int> &A, int B) {
    
    int right = 0, n = A.size(), count = 0, flag = 0, left = 0;
    
    while( right < n){
        
        flag = 0;
        for( int x = right+B-1 ; x >= left ; x--){
            
            if( A[x] == 1){
                
                left = x+1;
                flag = 1;
                count++;
                right = x+B; // All bulbs beyond i has light
                break;
            }
        }
        if( !flag)
            return -1;
        
        if( right >= n)
            return count;
    }
    return count;
}
