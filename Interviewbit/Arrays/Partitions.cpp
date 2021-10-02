// https://www.interviewbit.com/problems/partitions/
// O(N) 

int Solution::solve(int A, vector<int> &B) {
    
    int prefix[100005];
    prefix[0]=0;
    
    A = B.size();
    for( int i = 1; i <= A; i++)
        prefix[i] = prefix[i-1]+B[i-1];
        
    if( prefix[A] % 3 != 0)
        return 0;
        
    int s = prefix[A]/3, t = 2*prefix[A]/3, count = 0 , ans = 0;
    
    for( int i = 1 ; i < A; i++){
        
        if( prefix[i] == t)
            ans += count;
            
        if( prefix[i] == s)
            count++;
    }
    
    return ans;
}
