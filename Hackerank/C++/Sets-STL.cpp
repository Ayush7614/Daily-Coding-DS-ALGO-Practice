/* Problem Link:
   https://www.hackerrank.com/challenges/cpp-sets/problem 
   
Ques.
You will be given Q queries. Each query is of one of the following three types:

1 : Add an element x to the set.
2 : Delete an element x from the set. (If the number x is not present in the set, then do nothing).
3 : If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Sample Input:
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output:
Yes
No
No
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int i,n,x,y;
    set<int> s;

    cin>>n;

    for(i=0;i<n;i++){
        cin>>x>>y;    

        switch(x){
            case 1: s.insert(y);   //Inserts an integer y into the set s.
                    break;
            case 2: s.erase(y);   //Erases an integer y from the set s.
                    break;
            case 3: auto it=s.find(y);    
                    /* The set::find is a built-in function in C++ STL which 
                       returns an iterator to the element which is searched in the set container.
                       If the element is not found, then the iterator points to the position just after
                       the last element in the set. */

                    if(it==s.end()){    //set::end returns an iterator pointing to past the last element of the set container.
                        cout<<"No\n";    
                    }
                    else cout<<"Yes\n";
                    break;
        }
    }
      
    return 0;
}
