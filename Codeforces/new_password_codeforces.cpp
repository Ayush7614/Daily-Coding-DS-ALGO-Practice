#include <iostream>
#include <string>
using namespace std;
int main(){
    string s = "abcdefghijklmnopqrstuvwxyz";
    int n,k;
    cin>>n>>k;
    string s1="";
    for(int i=0;i<n;i++){
        s1+=s[i%k];
    }cout<<s1;
    
    return 0;
}