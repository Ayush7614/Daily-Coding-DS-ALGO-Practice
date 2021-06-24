/*
We are given a bar of chocolate composed of m*n square pieces. One should break the chocolate into single squares. Parts of the chocolate may be broken along the vertical and horizontal lines as indicated by the broken lines in the picture.

A single break of a part of the chocolate along a chosen vertical or horizontal line divides that part into two smaller ones. Each break of a part of the chocolate is charged a cost expressed by a positive integer. This cost does not depend on the size of the part that is being broken but only depends on the line the break goes along. Let us denote the costs of breaking along consecutive vertical lines with x1, x2, ..., xm-1 and along horizontal lines with y1, y2, ..., yn-1.

The cost of breaking the whole bar into single squares is the sum of the successive breaks. One should compute the minimal cost of breaking the whole chocolate into single squares.

For example, if we break the chocolate presented in the picture first along the horizontal lines, and next each obtained part along vertical lines then the cost of that breaking will be y1+y2+y3+4*(x1+x2+x3+x4+x5).

Task
Write a program that for each test case:

Reads the numbers x1, x2, ..., xm-1 and y1, y2, ..., yn-1
Computes the minimal cost of breaking the whole chocolate into single squares, writes the result.
Input
One integer in the first line, stating the number of test cases, followed by a blank line. There will be not more than 20 tests.

For each test case, at the first line there are two positive integers m and n separated by a single space, 2 <= m,n <= 1000. In the successive m-1 lines there are numbers x1, x2, ..., xm-1, one per line, 1 <= xi <= 1000. In the successive n-1 lines there are numbers y1, y2, ..., yn-1, one per line, 1 <= yi <= 1000.

The test cases will be separated by a single blank line.

Output
For each test case : write one integer - the minimal cost of breaking the whole chocolate into single squares.

Example
Input:
1

6 4
2
1
3
1
4
4
1
2

Output:
42


For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is
evaluated using following steps.

Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces

Cost 4 Horizontal cut Cost = 0 + 4*1 = 4
Cost 4 Vertical cut Cost = 4 + 4*2 = 12
Cost 3 Vertical cut Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut Cost = 18 + 2*3 = 24
Cost 2 Vertical cut Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut Cost = 30 + 1*4 = 34
Cost 1 Vertical cut Cost = 34 + 1*4 = 38
Cost 1 Vertical cut Cost = 38 + 1*4 = 42
*/


#include "iostream"
#include "algorithm"
using namespace std;


int minCostBreaker(int X[], int Y[], int M, int N)
{
  sort(X, X + M, greater<int>());
  sort(Y, Y + N, greater<int>());
  int totalCost = 0;
  int v = 1, h = 1;
  int i = 0, j = 0;
  while (i < M && j < N)
  {

    if (X[i] > Y[j])
    {
      totalCost += X[i] * v;
      h++;
      i++;
      // cout << totalCost << endl;
    }
    else
    {
      totalCost += Y[j] * h;
      v++;
      j++;
      cout << totalCost << endl;
    }
  }
  while(i< M)
  {
    totalCost += X[i] * v;
      h++;
      i++; 
      cout << totalCost << endl;

  }
  while(j<N)
  {
    totalCost += Y[j] * h;
      v++;
      j++;
  }
      cout << totalCost << endl;

  return totalCost;
}

int main()

{
  int m = 6, n = 4;
  int X[m - 1] = {2, 1, 3, 1, 4};
  int Y[n - 1] = {4, 1, 2};
  cout << minCostBreaker(X, Y, m - 1, n - 1) << endl;
  return 0;
}