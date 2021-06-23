/*question : There are n people in a circle waiting to be executed, starting from any position, 
a person starts executing the a'th person ahead of her, then the person after the one who is executed repeats the same task, 
  as there will be only one person surviving, we have to find the person who will remain alive.
  
  solution : 
*/

#include <iostream>
#include <vector>
using namespace std;

void alive(vector<int> &a, int k, int indx, int &ans)
{
    if (a.size() == 1)
    { // only one person will be left, which is the answer
        ans = a[0];
        return;
    }

    indx = (indx + k - 1) % a.size();
    v.erase(a.begin() + indx);
    alive(a, k, indx, ans);
}
int main()
{
    // let us use vector, to see if persons are not listed from 1 to n
    vector<int> lst;
    int q, k, ans = 0;
    cin >> q >> k;
    lst.reserve(n);
    for (int i = 0; i < q; i++)
    {
        lst.push_back(i + 1);
    }
    // lst = {1,2,3,4,..,n}
    alive(lst, k, 0, ans);
    cout << ans << endl;
    return 0;
}
/*

Test Case:

Input: 4 6
Output: 3

notations :
Space Complexity: O(n)
Time Complexity: O(n)

*/
