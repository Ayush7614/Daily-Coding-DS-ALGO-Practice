/*Input :
N = 9
Output:
2
Explanation:
1 and 4 are the only Perfect Squares
less than 9. So, the Output is 2.
*/



#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int countSquares(int N) 
    {
        //store the answer in count
        int count = 0;
      //running loop from 1 to squareroot of N
        for(int i=1; i<sqrt(N); i++)
        {
            if(i*i < N)
            {
                count++;
            }
        }
      //returning answer
        return count;
        
        
    }
};

int main() {
  //test cases
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
      //calling countsquares function from class solution
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
