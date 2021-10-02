// https://www.interviewbit.com/problems/prime-sum/
// O(n*sqrt(n)) Time

bool isprime( int n){
    for( int i = 2 ; i*i <= n ; i++){
        
        if( n%i == 0)
            return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
     vector<int> ans;
    
    for( int i = 2 ; i <= A/2 ; i++){
        if( isprime(i) && isprime(A-i)){
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
    return ans;
}
