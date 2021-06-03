#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n,c,d,sum1=0,sum2=0,sum11=0,sum22=0,e=0,f=0;
    cin>>t;
    while(t--){
       e=0;sum1=0;sum2=0;
            cin>>d>>c;
            d=d*2;
            int a[3];int b[3];

            for(int i=0;i<3;i++){
               cin>>a[i];
   
               sum1+=a[i];
            }

             for(int i=0;i<3;i++){
               cin>>b[i];
               sum2+=b[i];
            }
              
               
                  if(sum1<150)
                  e+=d/2;
                  
               
                  if(sum2<150)
                  e+=d/2;

             e+=sum1+sum2+c;
             f=sum1+sum2+d;
            if(e<f){cout<<"YES"<<endl;}
            else {cout<<"NO"<<endl;}



         }
         


 return 0;
}




  
	





  
	
