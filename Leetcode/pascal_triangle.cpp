/*link of this problem https://leetcode.com/problems/pascals-triangle/

 Given an integer numRows, return the first numRows of Pascal's triangle.

  In Pascal's triangle, each number is the sum of the two numbers directly above it.


  BRUTE FORCE APPROACH */
  void printPascal(int n)
   {

    // An auxiliary array to store
    // generated pscal triangle values
    int arr[n][n];

    // Iterate through every line and
    // print integer(s) in it
    for (int line = 0; line < n; line++)
    {
        // Every line has number of integers
        // equal to line number
        for (int i = 0; i <= line; i++)
        {
        // First and last values in every row are 1
        if (line == i || i == 0)
            arr[line][i] = 1;
        // Other values are sum of values just
        // above and left of above
        else
            arr[line][i] = arr[line - 1][i - 1] +
                            arr[line - 1][i];
        cout << arr[line][i] << " ";
        }
        cout << "\n";
    }
}


  //OPTIMIZED APPROACH

   class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>r(numRows);
        for(int i=0;i<numRows;i++){
             r[i].resize(i+1);
             r[i][0]=r[i][i]=1;

            for(int j=1;j<i;j++)
                 r[i][j]=r[i-1][j-1] + r[i-1][j];
        }
    return r;
    }
};

  /*EXAMPLE-1 :
       Input: numRows = 5
       Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
  EXAMPLE-2 :
        Input: numRows = 1
         Output: [[1]]*/
