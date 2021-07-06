#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &v, int temp)
{

  //base case
  if (v.size() == 0 or temp >= v[v.size() - 1])
  {
    v.push_back(temp);
    return;
  }
  int ele = v[v.size() - 1];
  v.pop_back();
  insert(v, temp);
  v.push_back(ele);
}
void bsort(vector<int> &v)
{
  //base case
  if (v.size() == 1)
    return;

  //hypothesis
  int ele = v[v.size() - 1];
  v.pop_back();
  bsort(v);

  //induction
  insert(v, ele);
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int ele;
    cin >> ele;
    v.push_back(ele);
  }
  bsort(v);
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}