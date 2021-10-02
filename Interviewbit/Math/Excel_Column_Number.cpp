// https://www.interviewbit.com/problems/excel-column-number/
O(N) Time

int Solution::titleToNumber(string A) {
    
    int ans =0;
    for( int i  = 0 ; i < A.length(); i++)
        ans+= (A[i]-'A'+1)*pow(26,A.length()-1-i);
    return ans;
}
