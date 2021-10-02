// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
// O(N) Time

int Solution::hammingDistance(const vector<int> &A) {
    
    long long int ans = 0;
    for( int bits = 0 ; bits < 32 ; bits++){
        
        int one = 0;
        for( int i = 0 ; i < A.size() ; i++){
            
            if( A[i]&(1<<bits))
                one++;
        }
        ans += one*(A.size()-one)*2;
        ans = ans % 1000000007;
    }
    return ans;
}
