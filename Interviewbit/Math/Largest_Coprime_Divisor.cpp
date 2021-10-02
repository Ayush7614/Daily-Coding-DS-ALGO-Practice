// https://www.interviewbit.com/problems/largest-coprime-divisor/
// 

int Solution::cpFact(int A, int B) {
    while( __gcd(A,B) > 1){
        A = A/__gcd(A,B);
    }
    return A;
}
