//Problem link: https://www.hackerrank.com/challenges/staircase/problem

#include <iostream>
using namespace std;

int main()
{
    //Initialize variables
    int num;

    //Enter size:
    cout << "Enter size of staircase: ";
    cin >> num;

    //Print out corresponding staircase
    for (int i = 1; i <= num; i++)
    {
        for(int j = i; j <= num - 1; j++)
        {
            cout<<" ";
        }
        for(int k = 1; k <= i; k++)
        {
            cout<<"#";
        }
        cout << endl;
    }
    return 0;
}

/*

Enter size of staircase: 6
     #
    ##
   ###
  ####
 #####
######

*/
