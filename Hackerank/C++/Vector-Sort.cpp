/*  Problem Link:
    https://www.hackerrank.com/challenges/vector-sort/problem */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int i,size,ele;
    vector<int> v;
    
    cin>>size;
    
    for(i=0;i<size;i++){
        cin>>ele;
        v.push_back(ele);     //pushes the element in the array as they are entered by the user
    }
    
    sort(v.begin(),v.end());   //inbuilt function in STL which sorts the array from beginning to end (parameters)
    
    for(i=0;i<size;i++){
        cout<<v[i]<<" ";      //displaying the contents of the array
    }
     
    return 0;
}
