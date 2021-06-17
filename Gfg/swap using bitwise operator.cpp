#include <iostream>
using namespace std;
int main()
{
  int x ,y;
  cin>>x>>y;
  
  //swapping using bitwise operator
  x = x^y;
  y = x^y;
  x = x^y;
   
  cout << x << " " << y << "\n";
  
  return 0;
}
//Input:2 3
//Output:3 2
