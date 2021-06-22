#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int values(char c){
        std::map<char,int> m;
        m.insert(pair<char,int>('I',1));
        m.insert(pair<char,int>('V',5));
        m.insert(pair<char,int>('X',10));
        m.insert(pair<char,int>('L',50));
        m.insert(pair<char,int>('C',100));
        m.insert(pair<char,int>('D',500));
        m.insert(pair<char,int>('M',1000));
        std::map<char,int>::iterator it;
        it=m.find(c);
        if(it!=m.end()){
            return it->second;
        }
        else return 0;
    }
    int romanToInt(string s) {
       int sum=0;
        int n=s.size();
        
        for(int i =0;i<n-1;i++){
            
                if((values(s[i]))>=(values(s[i+1]))){
                   // std::cout<<s[i-1]<<" "<<values(s[i-1])<<" "<<s[i]<<" "<<values(s[i])<<endl;
                    sum+=values(s[i]);

                }
                else{
                    sum-=values(s[i]);
                }
                //std::cout<<abs( sum);
            
        }
        sum+=values(s[n-1]);
        return abs(sum);
    
    }
};
int main(){
    string s;
    getline(cin,s);
    Solution sam;
    std::cout<<sam.romanToInt(s);
    return 0;
}