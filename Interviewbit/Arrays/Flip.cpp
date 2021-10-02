//https://www.interviewbit.com/problems/flip/
// O(N) Solution

vector<int> Solution::flip(string A) {
    
    int temp = 1, end = 0 , sum = INT_MAX, temp_sum = 0, start = 0;
    
    for(int i = 0 ; i < A.length(); i++){
        
        temp_sum += A[i] == '0' ? -1 : 1;
        
        if( temp_sum > 0){
           temp_sum = 0;
           temp = i+2;
        }
        
        else if( sum > temp_sum){
            start = temp;
            end = i+1;
            sum = temp_sum;
        }
    }
    if( sum == INT_MAX)
        return {};
        
    return {start,end};
}
