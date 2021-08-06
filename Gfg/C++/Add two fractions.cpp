//C++ Soulution of Add two fractions 

/*
Approach:

Calculated the GCD of denominators then 
as normal calculation of mathemathics for calculating
fractional addition
 
Constraints:
1 <= T <= 100
1 <= den1,den2,num1,num2 <= 1000

*/

#include<bits/stdc++.h>
using namespace std;

/*if the denominator is different then 
 we have to find the GCD of the denominator 
*/
int findGCD(int number1 , int number2)
{
    //check if number1 greater 
    if(number1>number2)
    {
       return  findGCD(number1-number2,number2);  
   }
   if(number1<number2)
   {
       return  findGCD(number1,number2-number1);
   }
   if(number1==number2)
   {
    return number1;
}
}

//Adding two fractions
void addFraction(int num1, int den1, int num2,int den2)
{

  int lcmden,nomi;
  //first calculated GCD of denominator
  lcmden = (den1*den2)/findGCD(den1,den2);
  
  nomi = num1 * (lcmden/den1) + num2 * (lcmden/den2);
  
  printf("%d/%d\n",nomi/findGCD(lcmden,nomi),lcmden/findGCD(lcmden,nomi));

}

//Driver Code Ends
int main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   cout.tie(NULL);
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 
    int testCase;
    cin>>testCase;
    while(testCase-->0)
    {
        int number1,denominator1,number2,denominator2,resultNum,resultDen;
        cin>>number1>>denominator1>>number2>>denominator2;
        addFraction(number1,denominator1,number2,denominator2);

    }
}

/*
Input
2
1 500 2 500
6 766 5 40

Output
3/500
407/3064

Complexity Analysis

Time Complexity:
O(n)

Space Complexity:
O(n)

*/