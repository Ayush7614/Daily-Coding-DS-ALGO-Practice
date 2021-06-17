/*An element is called a leader in an array, if all the elements to its right in the given array are neither greater or equal to that particular element*/
/* Ex: INPUT: n=6
  a[]={7,10,11,10,5,2}
      OUTPUT: 11,10,5,2 */


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    int c=a[n-1];
    cout<<c;
    for(int i=n-2;i>=0;i--)
     {
      if(a[i]>c)
       {
         c=a[i];
         cout<<c; // Output will be in the reverse order, that is: 2,5,10,11
       }
     }

}
