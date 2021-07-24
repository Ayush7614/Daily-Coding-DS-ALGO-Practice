/*QUESTION- You are given an array a[0…n−1] of length n which consists of non-negative integers. Note that array indices start from zero.

An array is called good if the parity of each index matches the parity of the element at that index. More formally, an array is good if for all i (0≤i≤n−1) the equality imod2=a[i]mod2 holds, where xmod2 is the remainder of dividing x by 2.

For example, the arrays [0,5,2,1] and [0,17,0,3] are good, and the array [2,4,6,7] is bad, because for i=1, the parities of i and a[i] are different: imod2=1mod2=1, but a[i]mod2=4mod2=0.

In one move, you can take any two elements of the array and swap them (these elements are not necessarily adjacent).

Find the minimum number of moves in which you can make the array a good, or say that this is not possible.

INPUT-
4
4
3 2 7 6
3
3 2 6
1
7
7
4 9 2 1 18 3 0

OUTPUT
2
1
-1
0
*/

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
