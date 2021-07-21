//codeforces solution 319/A
#include <iostream>

using namespace std;

int main() {
   long long int n,k,t;
   cin>>n>>k;
   if(n%2==0){
   t=n/2;}
   else{
   t=n/2+1;
   }
   if(k<=t){
       cout<<(2*k)-1<<endl;
   }
   if(k>t){
       cout<<2*(k-t)<<endl;
   }
   return 0;
}