//A program to search an element in a 2D //array 
//The 2D array should be sorted 
#include<bits/stdc++.h>
using namespace std;
int stairs(int a[100][100],int key,int n){
  int i=0;
  int j=n-1;
  while(i<n && j>=0){
    if(a[i][j]==key){
      cout<<"Element found at "<<i<<","<<j;
       return 1;
    }
    else if(a[i][j]>key){
      j--;
    }
    else 
    i++;
  }
  cout<<"Element not found";
  return 0;
}
int main(){
  int m,n,a[100][100],key;
  cin>>m>>n;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  cin>>key;
  
  stairs(a,key,n);
  return 0;
}
//Example:- 
//3 3 
// 1 2 3 
// 4 6 8 
// 12 34 56
//6 
//Output:- Element found at 1,1.


