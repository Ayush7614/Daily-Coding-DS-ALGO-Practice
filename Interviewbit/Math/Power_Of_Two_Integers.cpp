// https://www.interviewbit.com/problems/power-of-two-integers/
// O(sqrt(N)) Time

int Solution::isPower(int A) {
    
    if( A == 1)
        return 1;
        
    for(int i = 2 ; i*i <= A ; i++){
        
        float a = log(A)/log(i);
        if( floor(log(A)/log(i)) == a)
            return 1;
    }
    return 0;
}
