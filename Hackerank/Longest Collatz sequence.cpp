// Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler014/problem

#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long> arr(5000001);

unsigned long long countchain(unsigned long long num) {
  unsigned long long temp = 0;
  if (arr[num])
    return arr[num];
  if (num % 2 == 0) {
    temp = num / 2;
    arr[num] = 1 + countchain(temp);
    return arr[num];
  }
  temp = 3 * num + 1;
  unsigned long long count = 1;
  while (temp > 5000001) {
    if (temp % 2)
      temp = 3 * temp + 1;
    else
      temp /= 2;
    count++;
  }
  arr[num] = count + countchain(temp);
  return arr[num];
}

int main() {
  for (int i = 0; i < arr.size(); i++)
    arr[i] = 0;
  unsigned long long count = 0;
  arr[1] = 1;
  for (unsigned long long a = 2; a < 5000001; a = a * 2) {
    count++;
    arr[a] = count;
  }
  for (unsigned long long a = 1; a < 5000001; a++)
    countchain(a);
  vector<unsigned long long> results(5000001);
  results[1] = 1;
  for (unsigned long long a = 2; a < 5000001; a++) {
    if (arr[a] >= arr[results[a - 1]])
      results[a] = a;
    else
      results[a] = results[a - 1];
  }
  unsigned long long test_case = 0;
  cin >> test_case;
  unsigned long long end_number, max_answer = 0, result = 0;
  while (test_case--) {
    cin >> end_number;
    cout << results[end_number] << endl;
  }

  return 0;
}
