https://www.interviewbit.com/problems/greatest-common-divisor/
// 

int _gcd(int A, int B){
    
    if( B == 0)
        return A;
    return _gcd(B,A%B);
    
}
int Solution::gcd(int A, int B) {
       return _gcd(A,B);
}
