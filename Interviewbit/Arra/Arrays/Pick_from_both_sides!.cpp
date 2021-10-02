// https://www.interviewbit.com/problems/pick-from-both-sides/
// 0(N) Time O(1) Space

int Solution::solve(vector<int> &A, int B) {
    
    int sum = 0, ans = 0;
    
    for( int i = 0 ; i < B; i++)
        sum += A[i];
    
    int left = B-1, right = A.size()-1;
    ans = sum;
    
    while( left >= 0){
        
        sum = sum - A[left]+A[right];
        ans = max(ans,sum);
        left--;
        right--;
    }
    return ans;
}
