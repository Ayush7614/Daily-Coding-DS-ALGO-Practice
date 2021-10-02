// https://www.interviewbit.com/problems/balance-array/
// O(N) Time O(N) Space

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    int odd[n], even[n];
    odd[0] = A[0];
    
    if( n > 1)
        even[1] = A[1];
    else if( n == 1)
        return 1;
        
    int toteve = 0, totodd = 0;
    
    for( int i = 2 ; i < n ; i = i+2){
        odd[i] = odd[i-2]+A[i];
        totodd = odd[i];
    }
        
    for( int i = 3 ; i < n  ; i = i+2){
        even[i] = even[i-2]+A[i];
        toteve = even[i];
    }
      
    int ans  = 0;
    
    if( totodd- A[0] == toteve)
        ans += 1;
    
    if( totodd-A[0] == toteve-A[1]+A[0])
        ans++;
        
    for( int i = 2; i < n ; i++){
        if( i%2 == 0){
            
            if( odd[i-2] + (toteve-even[i-1]) == even[i-1]+totodd-odd[i] )
                ans++;
        }
        
        else{
            
            if( even[i-2] + (totodd-odd[i-1]) == odd[i-1]+toteve-even[i] )
                ans++;
        }
    }
    return ans;
}
