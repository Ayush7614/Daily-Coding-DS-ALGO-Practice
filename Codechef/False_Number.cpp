#include <bits/stdc++.h>
using namespace std;




int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        
        if(s[0]=='1'){
            // cout<< 10<<endl;
            // break;
            cout<<"10" + s.substr(1,s.size()-1)<<endl;
        }
        else {
            cout<< "1"+ s<<endl;
            
        }
        
    }
    return 0;
}



