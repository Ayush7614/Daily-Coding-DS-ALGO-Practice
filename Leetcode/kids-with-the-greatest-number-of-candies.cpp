/*
Test Case 1:
    Input: candies = [2,3,5,1,3], extraCandies = 3
    Output: [true,true,true,false,true]

Test Case 2:
    Input: candies = [4,2,1,1,2], extraCandies = 1
    Output: [true,false,false,false,false]

Test Case 3:
    Input: candies = [12,1,12], extraCandies = 10
    Output: [true,false,true]
*/



#include <bits/stdc++.h>
using namespace std;




vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> result;
        int size = candies.size(), max = candies[0];
        for (int i = 1; i < size; i++)
        {
            if (max < candies[i])
            {
                max = candies[i];
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;
    }


int main()
{
    vector<int> candies;
    vector<bool> result;
    string buffer;

    int extraCandies, num;
    cout << "Enter the candies: ";
    getline(cin, buffer);
    istringstream iss(buffer);
    while (iss >> num)
    {
        candies.push_back(num);
    }
    cout << "Enter the number of Extra Candies: ";
    cin >> extraCandies;
    result = kidsWithCandies(candies, extraCandies);
    cout << "Final Result: ";
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == 1)
            cout << "true ";
        else
            cout << "false ";
    }
    cout << endl;
}
