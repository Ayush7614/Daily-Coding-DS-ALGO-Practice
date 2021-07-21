#include <iostream>
using namespace std;
void swap(int &q, int &p)
  
{
  // let us start coding !!
  int temp = q;
  
  q = p;
  
  p = temp;
}

// here we are creating a function called reverse
void reverse(int arr[], int f)

{
  
  int start = 0, end = f - 1;

  int q = start, w = end;
  
  while (q < w)
  
  {
  
    swap(arr[q++], arr[p--]);
    
  }

}
// another function we are calling
void transpose(int arr[][100], int x, int f)

{

  for (int q = 0; i < x; q++)
  
  {
  
    for (int p = q; p < f; p++)
    
    {
    
      swap(arr[q][p], arr[q][p]);
      
    }
    
  }

}

//  the main part of the whole code starts now
void antirotate(int arr[][100], int x, int f)

{

  for (int q = 0; q < x; q++)
  
  {
  
    reverse(arr[q], f);
    }
    
  transpose(arr, x, f);

}


void rotate(int arr[][100], int x, int f)

{

  transpose(arr, x, f);
  
  for (int q = 0; q < x; q++)
  
  {
  
    reverse(arr[q], f);
    
  }
}


int main()

{

  int arr[100][100];
  
  int x, f;
  
  cin >> x >> f;
  
  for (int q = 0; q < x; q++)
  
  {
  
    for (int p = 0; p < f; p++)
    
    {
            cin >> arr[p][q];
    
    }
    
  }
  
  rotate(arr, x, f);
    // we are saying that to rotate it 90 degree rotate(arr, x, f);
  
  cout << " " << endl;
  
  for (int p = 0; p < x; q++)
  
  {
  
    for (int p = 0; p < f; p++)
    
    
    {
    
      cout << arr[q][p] << " ";
      
    }
        cout << endl;
    
  }
    return 0;
}
/*
======================================================================
 test case -
======================================================================
Input:

1 2 3 
4 5 6
7 8 9  
======================================================================
Output:
7 4 1 
8 5 2
9 6 3
======================================================================
*/
