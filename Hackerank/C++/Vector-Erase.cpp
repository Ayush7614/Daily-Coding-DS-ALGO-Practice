/* Problem Link:
   https://www.hackerrank.com/challenges/vector-erase/problem  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int i,size,ele,a,b,c;
    vector<int> v;

    cin>>size;

    for(i=0;i<size;i++){
        cin>>ele;
        v.push_back(ele);     //pushes the element in the vector array as entered by the user
    }

    cin>>a;

    v.erase(v.begin()+(a-1));   //Removes the element present at position a

    cin>>b>>c;
    
    /*Removes the elements in the range from start to end inclusive of the start and exclusive of the end,
    i.e. erases all the elements from bth element to cth element */
    v.erase(v.begin()+(b-1),v.begin()+(c-1));

    cout<<v.size()<<"\n";    //Displaying the size of vector array
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";     //Displaying the contents of vector array
    }
      
    return 0;
}
