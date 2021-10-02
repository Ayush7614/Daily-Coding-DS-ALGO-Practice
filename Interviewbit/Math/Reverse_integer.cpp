// https://www.interviewbit.com/problems/reverse-integer/
// O(logN)

int Solution::reverse(int A) {
    
    long long int B = 0;
    int sign = A < 0 ? 1 : 0;
    A = abs(A);
    
    while( A ){
        B = B*10+A%10;
        A = A/10;
        
        if( B > INT_MAX )
            return 0;
    }
    if( B > INT_MAX)
        return 0;
    
    if( sign )
        B = -B;
    
    if( B >= INT_MIN)
        return B;
        
    return 0;
}
