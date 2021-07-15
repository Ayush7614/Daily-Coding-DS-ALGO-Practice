/* Problem Link:
   https://www.hackerrank.com/challenges/vector-erase/problem 
   
Ques. 
You are provided with a vector of N integers. Then, you are given 2 queries. For the first query, you are provided with 1 integer, which denotes a position
in the vector. The value at this position in the vector needs to be erased. The next query consists of 2 integers denoting a range of the positions in the 
vector. The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the 
first query

Sample Input:
6
1 4 6 2 8 9
2
2 4

Sample Output:
3
1 8 9

Explanation:
The first query is to erase the 2nd element in the vector, which is 4. Then, modifed vector is {1 6 2 8 9}, we want to remove the range of 2~4, which 
means the 2nd and 3rd elements should be removed. Then 6 and 2 in the modified vector are removed and we finally get {1 8 9}
*/

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
