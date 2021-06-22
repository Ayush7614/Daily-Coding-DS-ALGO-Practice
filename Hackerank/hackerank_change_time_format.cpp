#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void convert(string s){
    int a=s[0]-'0';
    int b=s[1]-'0';
    int c=(s[0]-'0')*100000+(s[1]-'0')*10000+(s[3]-'0')*1000+(s[4]-'0')*100+(s[6]-'0')*10+s[7]-'0';
    if(s[8]=='P'){
        if(c>120000){
            s[0]=s[0];
            s[1]=s[1];
        }
        else{
            s[0]+=1;
            s[1]+=2;
        }
    }
    else{
        if(a*10+b==12){
            s[0]='0';
            s[1]='0';
        }
    }
    std::cout<<s;

}
int main(){
    string s;
    getline(cin,s);
    convert(s);
    return 0;
}