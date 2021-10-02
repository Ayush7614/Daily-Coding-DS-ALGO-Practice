// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
// log5(N)

int Solution::trailingZeroes(int A) {
    
    int ans = 0;
    while( A >= 5){
        ans += A/5;
        A = A/5;
    }
    return ans;
}

