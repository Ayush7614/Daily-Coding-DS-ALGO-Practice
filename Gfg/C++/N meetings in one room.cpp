#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        
        static bool comp(const pair<int, int>&a, const pair<int, int>&b){
            if(a.second == b.second)
                return a.first  <= b.first;
            return a.second < b.second;
        }
    
        int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector<pair<int, int>>vec;
        int i,c=0, fin;
        for(i=0;i<n;i++){
            vec.push_back({start[i], end[i]});
        }
        sort(vec.begin(), vec.end(), comp);
        
        for(i=0;i<n;){
            c++;
            fin=vec[i].second;
            i++;
            while(i < n && fin >= vec[i].first){
                i++;
            }
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
