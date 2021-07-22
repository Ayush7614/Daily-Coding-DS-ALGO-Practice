/*    
CODECHEF PROBLEM- TOTCRT

Problem Link: https://www.codechef.com/START5C/problems/TOTCRT/

Problem Statement: 
Codechef challenges have three divisions. In one challenge, there are N problems in each division, but some problems may be shared among multiple divisions. Each problem is uniquely identified by a code — a string containing only uppercase English letters. Each participant can only submit in one of the divisions.
Chef wants to find the number of correct solutions, in total among all 3 divisions, for each problem. Given a list of N problem codes with the numbers of correct solutions for each problem in each division, find the total number of correct solutions for each problem and sort them in non-decreasing order.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        unordered_map<string,int> mp;
        int n;
        cin>>n;
        for(int i=0;i<n*3;i++){
            int c;
            string s;
            cin>>s>>c;
            if(mp.find(s)!=mp.end()){
                mp[s]=mp[s]+c ;
            }
            else{
                mp.insert({s,c});
                }
        }
        vector<int> v ;
        for(auto i:mp)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;          
}
    

/*
Input-
3
1
A 1
B 2
C 3
2
AA 1
AB 1
AB 1
AC 1
AC 1
AD 1
1
Z 100
Z 100
Z 100

Output-
1 2 3
1 1 2 2
300


Explanation:
Example case 1: There is only 1 problem in each division and no problems are shared among divisions, so the total number of distinct problems is 3 and the numbers of solutions are: 1 for "A", 2 for "B", 3 for "C".

Example case 2: There are 2 problems in each division and each pair of consecutive divisions shares 1 problem, so the total number of distinct problems is 4 and the numbers of solutions are: 1 for "AA", 2 for "AB", 2 for "AC", 1 for "AD". We need to sort them in non-decreasing order, so the final answer is (1,1,2,2).

Example case 3: There is only 1 problem "Z" in the entire contest, shared among all divisions, and the number of solutions for it is 300.

*/
