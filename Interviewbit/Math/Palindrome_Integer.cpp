// https://www.interviewbit.com/problems/palindrome-integer/
// O(log10(N) Time

int Solution::isPalindrome(int A) {
    
    if( A < 0)
        return 0;
        
    long long int B = A, C= 0;
    while(B){
        C = C*10+B%10;
        B = B/10;
    }
    return A==C;
}
