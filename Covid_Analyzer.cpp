#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long int arr[90];
    arr[0] = 1, arr[1] = 2;
    for (int i = 2; i < 90; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        cout << arr[num - 1] << endl;
    }
    return 0;
}
