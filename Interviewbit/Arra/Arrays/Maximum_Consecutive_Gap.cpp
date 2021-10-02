// https://www.interviewbit.com/problems/maximum-consecutive-gap/
// 0(N) Time O(N) Space

int Solution::maximumGap(const vector<int> &A) {
    
    priority_queue<int> qu(A);
    int ans = INT_MIN;
    
    while(!qu.empty()){
        
        int A = qu.top();
        qu.pop();
        int B = qu.top();
        
        ans = max(ans,A-B);
    }
    return ans;    
}
