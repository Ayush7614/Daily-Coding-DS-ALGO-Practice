/*link of this problem https://leetcode.com/problems/pascals-triangle-ii/

 Given an integer numRows, return the first numRows of Pascal's triangle.

  In Pascal's triangle, each number is the sum of the two numbers directly above it.*/

#include<bits/stdc++.h>
using namespace std;
     vector<int>getRow(int rowIndex) {
        vector<int>r(rowIndex+1,1);
        for(int i=0;i<rowIndex;i++){
             for(int j=i;j>0;j--)
                r[j]=r[j-1] + r[j];
        }
      return r;
    }



int main(){
   int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
    vector<int>v=getRow(n);
      for(int i : v)
           cout<<i<<" ";

   }
}

  /*EXAMPLE-1 :
       Input: numRows = 3
       Output: [1 3 3 1]
  EXAMPLE-2 :
        Input: numRows = 2
         Output: [1 2 1]*/
