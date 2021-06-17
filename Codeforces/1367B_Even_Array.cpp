#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Testcase;
    cin >> Testcase;
    for (int i = 0; i < Testcase; i++)
    {
        int num, even_num = 0, odd_num = 0, count = 0;
        cin >> num;
        int arr[num];
        for (int j = 0; j < num; j++)
        {
            cin >> arr[j];
            if (arr[j] % 2 == 0)
                even_num++;
            else
                odd_num++;
        }
        if (even_num == odd_num || ((num % 2 != 0) && (even_num == odd_num + 1)))
        {
            for (int j = 0; j < num; j++)
            {
                if ((j % 2) != (arr[j] % 2))
                {
                    for (int k = j + 1; k < num; k++)
                    {
                        if ((k % 2) != (arr[k] % 2) && (arr[j] % 2) != (arr[k] % 2))
                        {
                            int x = arr[j];
                            arr[j] = arr[k];
                            arr[k] = x;
                            count++;
                            break;
                        }
                    }
                }
            }
            cout << count << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}