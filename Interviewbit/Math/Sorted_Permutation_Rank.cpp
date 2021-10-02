// https://www.interviewbit.com/problems/sorted-permutation-rank/
// O(N*N)

int fact( int k){
    
    long long int ans = 1;
    for( int i = 2 ; i <= k ; i++){
        ans *=i % 1000003;
        ans = ans % 1000003;
    }
    return ans% 1000003;
}
    int Solution::findRank(string A) {
    int ans = 0;
    int n=A.length();
    
    for(int i=0;i<n-1;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i])
                count++;
        }   
        ans+=( (count*fact(n-i-1)) )% 1000003;
    }
    return (ans+1 )% 1000003;
}

