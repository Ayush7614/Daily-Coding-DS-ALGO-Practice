#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements= ";
    cin >> n;

    int initial[n], final[n];
    cout << "Enter elements= ";
    for (int i = 0; i < n; i++)
    {
        cin >> initial[i];
    }
    for (int i = 0; i < n; i++)
    {
        final[i] = initial[i]; //copying elements of initial array to final array
    }
    cout << "The final array is= " << endl;
    for (int i = 0; i < n; i++)
        cout << final[i] << " ";
    return 0;
}