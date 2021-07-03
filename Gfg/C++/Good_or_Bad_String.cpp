/*
Problem: Write a program to check whether a string is Good or Bad according to the criteria given below
Criteria: If a string contain more than 5 vowels or 3 constant continuously then it is a bad string else good
*/
#include <iostream>

using namespace std;

// function to check whether the character is Vowel or not
int isVowel(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return 1;
  else
    return 0;
}
// function to check whether the string is good or bad
int Good_or_Bad(string s1)
{
    int vowel = 0;
    int constant = 0;
    int res = 1;

    for (int i = 0; i < s1.length(); i++)
    {
        /* if the character is vowel than assign 0 to constant and increment vowel by one and if the vowel count is greater
        than 5 then assign 0 to res means it a bad string */
      if (isVowel(s1[i]))
        {
        constant = 0;
        vowel++;
        if (vowel > 5)
        {
          res = 0;
          break;
        }
        /* if the character is ? that means it can be both constant and vowel so increment constant
        and vowel by 1 and check whether the string become bad */
      } else if (s1[i] == '?')
      {

        constant++;
        vowel++;
        if (constant > 3 || vowel > 5)
        {
          res = 0;
          break;
        }
      }
       /* if the else statement runs means the character is a constant then assign 0 to vowel and
       increment constant by 1 and check whether the string becomes bad */
      else
      {

        vowel = 0;
        constant++;
        if (constant > 3)
        {
          res = 0;
          break;
        }
      }
    }
    return res;
}
// driver code
int main()
{
  int t,res;
  string s1;
  cout<<"Enter the number of testcase: ";
  cin >> t;
  cin.ignore(1, '\n');
  while (t--)
   {
       cout<<"Enter a string: ";
    getline(cin, s1);
    res=Good_or_Bad(s1);
    cout << res << "\n";
  }
  return 0;
}
/*
Example
Input: aeiou?
Output: 0(it is a bad string)
Time complexity: O(N) where n is the length of the string
*/
