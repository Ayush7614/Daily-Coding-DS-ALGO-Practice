/*
TEST CASE 1:
    INPUT:
        Enter the total Numbers: 3
        Enter the Number 1 : 2
        Enter the Number 2 : 3
        Enter the Number 3 : 4
        Enter the Number 4 : 5
        Enter the Number 5 : 5
        Enter the Number 6 : 5
    OUTPUT:
        NO we can not split

TEST CASE 2:
    INPUT:
        Enter the total Numbers: 2
        Enter the Number 1 : 2
        Enter the Number 2 : 3
        Enter the Number 3 : 4
        Enter the Number 4 : 5
    OUTPUT:
        YES  we can split

TEST CASE 3:
    INPUT:
        Enter the total Numbers: 4
        Enter the Number 1 : 1
        Enter the Number 2 : 5
        Enter the Number 3 : 3
        Enter the Number 4 : 2
        Enter the Number 5 : 6
        Enter the Number 6 : 7
        Enter the Number 7 : 3
        Enter the Number 8 : 4
    OUTPUT:
        NO we can not split
*/

#include <bits/stdc++.h>
using namespace std;

//DRIVER FUNCTION//
int main()
{

    int num, even = 0, odd = 0;
    cout << "Enter the total Numbers: ";
    cin >> num;
    int arr[2 * num];

    for (int i = 0; i < 2 * num; i++)
    {
        cout << "Enter the Number " << i + 1 << " : ";
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (even > odd)
    {
        if (odd == num)
        {
            cout << "YES we can split" << endl;
        }
        else
        {
            cout << "NO we can not split" << endl;
        }
    }
    else
    {
        if (even == num)
        {
            cout << "YES  we can split" << endl;
        }
        else
        {
            cout << "NO we can not split" << endl;
        }
    }

    return 0;
}