#include <bits/stdc++.h>
using namespace std;
#define ll long long̥

bool binarySearch(const vector<int> &vect, int n, int key)
{
    int l = 0;
    int r = n - 1;
    while (r >= l)
    {
        int mid = (r + l + 1) / 2;
        if (vect[mid] == key)
        {
            return true;
        }
        else if (key > vect[mid])
        {
            l = mid + 1;
        }
        else if (key < vect[mid])
        {
            r = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> vect;
    int n;
    cin >> n; //size of array
    int key;  //integer to search
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vect.push_back(a); //array data input̥
    }
    sort(vect.begin(), vect.end()); //sorting the vector

    if (binarySearch(vect, n, key))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

// Sample Input:
// 5
// 2
// 1 2 3 4 5

// Output : True
