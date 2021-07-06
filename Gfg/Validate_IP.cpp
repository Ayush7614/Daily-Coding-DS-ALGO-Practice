/* Validate an IP Address:
Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string s as its only argument .

Example 1:
Input:
ip = 222.111.111.111
Output: Valid

Example 2:
Input:
ip = 5555..555
Output: Not valid

Explanation: 5555..555 is not a valid
ip address, as the middle two portions
are missing.

Expected Time Complexity: O(N), N = length of string.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of string <=50

*/

// Solution for the above question

#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define DELIM "."

/* function to check whether the 
   string passed is valid ip or not */
bool valid_part(char* s)
{
    int n = strlen(s);
    
    // if length of passed string is 
    // more than 3 then it is not valid
    if (n > 3)
        return false;
    
    // check if the string only contains digits
    for (int i = 0; i < n; i++)
        if ((s[i] >= '0' && s[i] <= '9') == false)
            return false;
    string str(s);
    
    // if the string is "00" or "001" or 
    // "05" etc then it is not valid
    if (str.find('0') == 0 && n > 1)
        return false;
    stringstream geek(str);
    int x;
    geek >> x;
    
    // valid if no. is between 0 to 255
    return (x >= 0 && x <= 255);
}

/* return 1 if IP string is 
valid, else return 0 */
int is_valid_ip(char* ip_str)
{
    // if empty string then return false
    if (ip_str == NULL)
        return 0;
    int i, num, dots = 0;
    int len = strlen(ip_str);
    int count = 0;
    
    // the number dots should be 3
    for (int i = 0; i < len; i++)
        if (ip_str[i] == '.')
            count++;
    if (count != 3)
        return false;
    
    // Link for strtok()
  
    char *ptr = strtok(ip_str, DELIM);
    if (ptr == NULL)
        return 0;

    while (ptr) {

        /* after parsing string, it must be valid */
        if (valid_part(ptr)) 
        {
            /* parse remaining string */
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }

    /* valid IP string must contain 3 dots */
    // this is for the cases such as 1...1 where
    // after iteration of the string we find 
    // it is not valid
    if (dots != 3)
        return 0;
    return 1;
}


int main()
{
    char ip[200];
    cout<<"Enter the ip address to check: ";
    cin>>ip;
    is_valid_ip(ip) ? cout<<"\nValid" : cout<<"\nNot valid";
    return 0;
}

/*Time complexity : O(n)
  Space complexity : O(1)
 */
