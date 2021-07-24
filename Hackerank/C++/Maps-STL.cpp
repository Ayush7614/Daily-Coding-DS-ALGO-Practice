/* Problem Link:
    https://www.hackerrank.com/challenges/cpp-maps/problem 
    
Ques.
You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students. Each student can have multiple answer sheets. So the teacher has Q queries:

X Y : Add the marks Y to the student whose name is X.
X : Erase the marks of the students whose name is X.
X : Print the marks of the students whose name is X. (If X didn't get any marks print 0.)

Sample Input:
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Sample Output:
30
20
0
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int i,n,x,y;
    string s;
    map<string,int>m;

    cin>>n;

    for(i=0;i<n;i++){
        cin>>x;

        switch(x){
            case 1: cin>>s;   //enter name of student
                    cin>>y;   //enter marks of student
                    m[s]+=y;  //Add the marks y to the student whose name is s.
                    break;

            case 2: cin>>s;    //enter name of student
                    m.erase(s);  //Erase the marks of the students whose name is s.
                    break;

            case 3: cin>>s;  //enter name of student
                    auto it=m.find(s); 
                    /* The set::find is a built-in function in C++ STL which returns an 
                       iterator to the element which is searched in the set container. If 
                       the element is not found, then the iterator points to the position just 
                       after the last element in the set.  */

                    //Print the marks of the students whose name is s. (If s didn't get any marks print 0.)
                    if(it==m.end()) cout<<"0\n";  
                    else cout<<m[s]<<"\n";
                    break;
        }
    }
    
    return 0;
}
