
/*https://www.codechef.com/LTIME96C/problems/TWINGFT*/





#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
 ios_base::sync_with_stdio(false); // fast input output
 cin.tie(NULL);
long long int test;
 cin>>test;   //taking test cases number
 for(int i=0;i<test;i++){         //test cases loop
     long long int N=0,K=0;            
     cin>>N>>K;                //taking input of N,K
     int *gift=new int (N);
     for(int y=0;y<N;y++){
         cin>>gift[y];         // taking input of gifts prices
     }

    sort(gift,gift+N);            // sorting
   long long int chef=0,brother=0;   
  
   while(K--){                   // condition is given (2*K+1<=N) 
        N--;                     // beavuse array length N and it's elemnts will start from N-1
        chef=chef+gift[N];      //assuming chef taking first gift
        N--;                    // we want the next previous gift
        
        
        brother=brother+gift[N]; //chef brother taking second gift
        
        
   }
    if(N!=0){
    N--;                                                                         
    brother=brother+gift[N];      //it's given that the second person who will take gifts can take one extra gifts at the last turn (N-- because we want the next gift of the last gift was take)
    }
    if(chef>brother){ 
        cout<<chef<<endl;

    }                                 // according to condition the max num gift will be printed
    else{
        cout<<brother<<endl;
    }
    
}
}
