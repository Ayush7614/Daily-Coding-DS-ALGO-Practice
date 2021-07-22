/* Algorithm :
Since in Sudoku same digit should not be present in same column,row and that subgrid in which it is present.
So we will use set data structure which only contains unique element. So for each number, we will calculate
"ROW"+Row_No+Digit , "COL"+Col_No+Digit, "BOX"+Box_No+Digit in string form and put it in set if already not present
and if any digit is repeated in the set means Sudoku is not possible (we will return false).

*/

#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
        
        set<string>s;
        int i,j;
            
        for(i=0;i<9;i++)
        {
             for(j=0;j<9;j++)
             {
                    if(board[i][j]!='.') // Consider digits only
                    {
                        string s1,s2,s3,s4;
                        s1=to_string(i); 
                        s2=to_string(j);
                        s3=to_string((i/3)*3+j/3); // Calculating Box number
                        s4=to_string(board[i][j]);
                        
                        
                          
                        if(s.count("ROW"+s1+s4)==1 || s.count("COL"+s2+s4)==1 || s.count("BOX"+s3+s4)==1) // same digit is already present
                                        return false; // Sudoku is invalid
            
                        if(s.count("ROW"+s1+s4)==0)
                            s.insert("ROW"+s1+s4); // inserting "ROW"+Row_No+Digit
            
                        
                        if(s.count("COL"+s2+s4)==0)
                            s.insert("COL"+s2+s4); // inserting "COL"+Col_No+Digit
                        
                        if(s.count("BOX"+s3+s4)==0)
                                     s.insert("BOX"+s3+s4); // inserting "BOX"+Box_No+Digit
                    }
             }
                    
      
            
        }
        
        return true;
        
}

int main()
{
    vector<vector<char>>v;
    
    for(int i=0;i<9;i++)
    {
        vector<char>vec;
        for(int j=0;j<9;j++)
        {
            char c;
            cin>>c;
            vec.push_back(c);

        }

        v.push_back(vec);

    }

    int ans=isValidSudoku(v);

    if(ans==1)
        cout<<"Sudoku is valid";
    else
        cout<<"Sudoku is invalid";
        
    return 0;

}

/*
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

Output:
true (Sudoku is valid)

*/
