#include<bits/stdc++.h>

using namespace std; 

class Solution{
public:
int t[500][500];
int isPallindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int PP(string str,int i,int j){
    if(t[i][j]!=-1)
        return t[i][j];
    if(i>=j || isPallindrome(str,i,j)){
        t[i][j]=0;
        return 0;
    }
    int ans = INT_MAX,temp;
    for(int k=i;k<j;k++){
        if(isPallindrome(str,i,k)){
            temp = 1+PP(str,k+1,j);
            ans = min(ans,temp);
        }
    }
    return t[i][j] = ans;
}
int palindromicPartition(string str){
    memset(t,-1,sizeof(t));
    return PP(str,0,str.length()-1);
}
};
  
 int main()
 {
   int t;
   cin>>t;
   while(t--)
   {
     string str;
     cin>>str;
     Solution ob;
     cout<<ob.palindromicPartition(str)<<endl;
   }
   return 0;
 }
