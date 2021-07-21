 /*Algorithm:
 We will store the sorted string in map and add it's anagrams after sorting and comparing while traversing the 
 array of string(input).
*/
 
 #include<bits/stdc++.h>

  using namespace std;

// Function to group Anagrams
 vector<vector<string>> groupAnagrams(vector<string>& strs) 
 {
        
        unordered_map<string,vector<string>>m;
        
        int n=strs.size();
        string temp;
        
        for(int i=0;i<n;i++)
        {
            temp=strs[i]; 
            sort(strs[i].begin(),strs[i].end()); // Sorting and storing in map
            
            m[strs[i]].push_back(temp); // mapping the anagrams
        }
        vector<vector<string>>ans;
        
         for(auto x:m){
            ans.push_back(x.second); // pushing the mapped group of anagrams in ans vector
        }
        
        return ans;
            
            
 }

 int main()
 {
        vector<string>v;
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }

        vector<vector<string>>ans=groupAnagrams(v);

        // printing ans 
        for(int i = 0;i<ans.size();i++)
        {
             cout << "[";
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j] << ", ";
            }
            cout << "]";
         }
    
         return 0;

  }
  
  /*Input:
  n=6
  v={"eat","tea", "tan", "ate", "nat", "bat"}

  Output:
  [bat ][eat, tea, ate ][ tan, nat ]

  */
  
