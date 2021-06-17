#include "iostream"
#include <limits.h>
using namespace std;

int maxSubArraySum(int array[], int size)
{
  int curr_sum = 0;
  int max_sum = INT_MIN;
  for (int i = 0; i < size; i++)
  {
    curr_sum += array[i];
    if (curr_sum > max_sum)
      max_sum = curr_sum;
    if (curr_sum < 0)
      curr_sum = 0;
  }
  return max_sum;
}

int main()
{
  int n;
  cout << "Enter no of elements in the array : ";
  cin >> n;
  int array[n];
  cout << "Enter Elements : ";
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  cout << "Maximum value of subarray : " << maxSubArraySum(array, n);
  return 0;
}