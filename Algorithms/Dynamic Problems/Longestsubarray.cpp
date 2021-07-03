#include<iostream>
#include<unordered_map>
using namespace std;

int Longestsub(int arr[],int a,int q){
    unordered_map<int, int> b; 
    int pre = 0;
    int bur = 0;

    for(int i=0;i<a;i++){
        pre += arr[i];

        if(pre==k){

            //here we use i+1 because, 0 is based indexing
           bur = max(bur, i+1); 
        }

        //repeating number
        if(b.find(pre-q)!=b.end()){ 

            //here i is the first occurence of csum

           bur = max(bur, i - b[pre-q]);         }
        else{
        //lets store the store the i
          b[pre] = i;
        }
    }
    return bur;
}

int main(){
     int a,q;
     cin >> a>>q;

     int arr[a];

     for(int i=0;i<a;i++){
         cin >> arr[i];
     } 

     cout<<Longestsub(arr,a,q);
  
  return 0;
}

/* 

    Test case :
    Input :
    5 15
    10 5 2 7 1 

    Output :
    4
*/




