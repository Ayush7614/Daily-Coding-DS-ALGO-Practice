/*
*****MAIN MENU******
1. Convert into Months
2. Convert into Day
3. Convert into Hours
4. Convert into Minutes
5. Convert into Seconds
6. EXIT

    Enter the year you want to convert: 25
    Enter any one of above option: 1
        Total Months in 25 years: 300

    Enter the year you want to convert: 25
    Enter any one of above option: 2
        Total Days in 25 years: 9125

    Enter the year you want to convert: 25
    Enter any one of above option: 3
        Total Hours in 25 years: 219000

    Enter the year you want to convert: 25
    Enter any one of above option: 4
        Total Minutes in 25 years: 13140000

    Enter the year you want to convert: 25
    Enter any one of above option: 5
        Total Seconds in 25 years: 788400000
*/

#include <bits/stdc++.h>
using namespace std;

//Function to convert year into month//
void year_to_month(int year)
{
    cout << "Total Months in " << year << " years: " << year * 12 << endl;
}

//Function to convert year into Day//
void year_to_day(int year)
{
    cout << "Total Days in " << year << " years: " << year * 365 << endl;
}

//Function to convert year into Hour//
void year_to_hour(int year)
{
    cout << "Total Hours in " << year << " years: " << year * 8760 << endl;
}

//Function to convert year into Minutes//
void year_to_minutes(int year)
{
    cout << "Total Minutes in " << year << " years: " << year * 525600 << endl;
}

//Function to convert year into Seconds//
void year_to_seconds(int year)
{
    cout << "Total Seconds in " << year << " years: " << year * 31536000 << endl;
}

//Driver Function//
int main()
{
    int num, year;
    do
    {
        cout << "*****MAIN MENU******" << endl;
        cout << "1. Convert into Months" << endl;
        cout << "2. Convert into Day" << endl;
        cout << "3. Convert into Hours" << endl;
        cout << "4. Convert into Minutes" << endl;
        cout << "5. Convert into Seconds" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter the year you want to convert: ";
        cin >> year;
        cout << "Enter any one of above option: ";
        cin >> num;
        switch (num)
        {
        case 1:
            year_to_month(year);
            break;
        case 2:
            year_to_day(year);
            break;
        case 3:
            year_to_hour(year);
            break;
        case 4:
            year_to_minutes(year);
            break;
        case 5:
            year_to_seconds(year);
            break;
        case 6:
            return 0;

        default:
            cout << "Enter any valid Option!" << endl;
        }
    } while (1);
    return 0;
}
