//C++ Solution of Day of the week problem
/*
Problem Statement:
Write a program that calculates the day of the week 
for any particular date in the past or future.

Approach:
Accepted data,month,year in the form(dd-mm-yyyy)
prestored the day of week in strin array 
Then performed simple mathematical calculation for 
calculating day number for that we calculated total
days in provided date , finally we performed mod 7 
on calculated day number to get day of that number, 
then result is returned.
*/
#include<bits/stdc++.h> 
 using namespace std; 
 class Solution
 {
 public:
string CalcDayOfWeek(unsigned long year, unsigned long month, unsigned long day)
{
  string dayInWeek[] = 
  {
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
    "Monday",
    "Tuesday"
  };
  month = (month + 9) % 12;
  year -= month / 10;
  unsigned long day_number =(365*year + year/4 - year/100 + year/400 + (month*306 + 5)/10 + (day - 1));

  return dayInWeek[day_number% 7];
}
 };
   int main() 
   { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   cout.tie(NULL);
   int testCases;
   cin>>testCases; 
   while(testCases-->0) 
   { 
    unsigned long year,month,day;
    cin>>day>>month>>year;    
    Solution obj;
     cout<<obj.CalcDayOfWeek(year, month, day);
     
      cout<<endl; 
   } 
   return 0; 
}

/*
Input:
3
28 12 1995
30 8 2010
27 7 2021

Output:
Thursday
Monday
Tuesday

Constraints:
1 <= day <= 31
1 <= month <= 12
1990 <= year <= 2100

Complexity Analysis:
Time Complexity: O(1)
Auxiliary Space: O(1)

*/