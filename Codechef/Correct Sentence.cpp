#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << endl;
    while (t--)
    {
        int x;
        // vector<string> v;
        cin >> x;
        cin.ignore();
        char str[x][100];
        for (int i = 0; i < x; i++)
        {
            scanf("%s", str[i]);
        }
        int q = 0;
        cout<<endl;
        for (int i = 0; i < x; i++)
        {
            if (str[i][0] >= 'a' && str[i][0] <= 'z')
            {
                if (str[i][0] >= 'a' && str[i][0] <= 'm')
                {
                    for (int j = 0; str[i][j] != '\0'; j++)
                    {
                        if (!(str[i][j] >= 'a' && str[i][j] <= 'm'))
                        {
                            q = 1;
                            break;
                        }
                    }
                }
                else
                {
                    q = 1;
                }
            }
            else
            {
                if (str[i][0] >= 'N' && str[i][0] <= 'Z')
                {
                    for (int j = 0; str[i][j] != '\0'; j++)
                    {
                        if (!(str[i][j] >= 'N' && str[i][j] <= 'Z'))
                        {
                            q = 1;
                            break;
                        }
                    }
                }
                else
                    q = 1;
            }
            if (q == 1)
                break;
        }
        if (q == 1)
            cout << "No"<<endl;
        else
            cout << "Yes"<<endl;
    }

    return 0;
}


//sample input
3
1 aN
2 ab NO
3 A N D


//sample output
No
Yes
No

