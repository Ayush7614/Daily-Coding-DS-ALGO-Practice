
class Solution {
public:
    
    void helper(vector<int> &candidates,int target,vector<vector<int>> &res,
                                            vector<int> &combination,int begin)
    {
        if(!target)
        {
            res.push_back(combination);  // if target is 0 add to resultant vector
            return;
        }
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];++i) 
        {
            combination.push_back(candidates[i]);
            helper(candidates,target-candidates[i],res,combination,i);  // unlimited times
            combination.pop_back();                                     // backtrack
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());    // sort 
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        vector<vector<int>>res;                       // resultant vector
        vector<int>combination;                       // trying combinations
        
        helper(candidates,target,res,combination,0);
        return res;
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}

