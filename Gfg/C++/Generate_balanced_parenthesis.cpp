#include<bits/stdc++.h>
using namespace std;
// intially openings =closings=number of pairs
void solve(int openings,int closings,string op,vector<string>&ans){
    // when all openings & closings are used ,we got one balanced parenthesis
    if(openings==0 && closings==0){
        ans.push_back(op);
        return;
    }
    // since openings brackets can be used anywhere until it is greater than zero
     if(openings!=0){
         string op1=op;
         op1.push_back('(');
         solve(openings-1,closings,op1,ans);
     }
    //  but closings can only be used when closings left are greater than openings left. 
     if(closings>openings){
    string op2=op;
    op2.push_back(')');
    solve(openings,closings-1,op2,ans);
     }
}

int main(){
    int number_of_pairs;
    cin>>number_of_pairs;
    string s;
      vector<string>ans;
      solve(number_of_pairs,number_of_pairs,s,ans);
      for(auto x:ans){
          cout<<x<<endl;
      }

}

// example :
// number_of_pairs=2
// output:
// ()()
// (())