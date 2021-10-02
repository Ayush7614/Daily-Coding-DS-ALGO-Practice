// https://www.interviewbit.com/problems/sort-array-with-squares/
// O(N) time

vector<int> Solution::solve(vector<int> &A) {
    
    map<int,int>mp;
    
    for( int i = 0 ; i < A.size() ; i++)
        mp[A[i]*A[i]]++;
    
    vector<int> ans;
    
    for( auto x : mp){
        
        while(x.second-- >  0)
            ans.push_back(x.first);
    }
    return ans;
}
