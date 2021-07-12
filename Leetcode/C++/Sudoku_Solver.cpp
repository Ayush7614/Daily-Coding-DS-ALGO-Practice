// Sudoku Solver (Hard) probem of LeetCode

/*
# First test case
Input: board = [["5","3",".",".","7",".",".",".","."],
				["6",".",".","1","9","5",".",".","."],
				[".","9","8",".",".",".",".","6","."],
				["8",".",".",".","6",".",".",".","3"],
				["4",".",".","8",".","3",".",".","1"],
				["7",".",".",".","2",".",".",".","6"],
				[".","6",".",".",".",".","2","8","."],
				[".",".",".","4","1","9",".",".","5"],
				[".",".",".",".","8",".",".","7","9"]]
				
Output: [["5","3","4","6","7","8","9","1","2"],
		["6","7","2","1","9","5","3","4","8"],
		["1","9","8","3","4","2","5","6","7"],
		["8","5","9","7","6","1","4","2","3"],
		["4","2","6","8","5","3","7","9","1"],
		["7","1","3","9","2","4","8","5","6"],
		["9","6","1","5","3","7","2","8","4"],
		["2","8","7","4","1","9","6","3","5"],
		["3","4","5","2","8","6","1","7","9"]]
*/

# include<bits/stdc++.h>
using namespace std;

//class solution
class Solution {
public: 
	//this function checks the validity of position given by (row, col)
    bool is_valid(int row, int col, vector<vector<char>>&board, char c)
	{
		//check all column of row if it contain character c if yes return false
        for(int i=0; i<board.size();i++)
		{
            if(board[row][i]!='.' && board[row][i]==c)return false;
        }
		//check all row of given col if it contain character c if yes return false
        for(int i=0; i<board.size();i++)
		{
            if(board[i][col]!='.' && board[i][col]==c)return false;
        }
		//check if submatrix of 3x3 conatin this charcter c if yes return false
        for(int i=0; i<board.size();i++)
		{
            if(board[3*(row/3)+(i/3)][3*(col/3)+i%3]!='.' && board[3*(row/3)+(i/3)][3*(col/3)+i%3]==c)return false;
        }
        return true; //otherwise return means character can be placed at position (row,col)
    }

    bool solve(vector<vector<char>>&board)
	{
        int n = board.size(),m= board[0].size();  //n= number of rows, m = number of columns
		//traverse the cells of board one by one        
        for(int i=0;i<n;i++)
		{
            for(int j=0;j<m;j++)
			{
                if(board[i][j]=='.')
				{ 	
					//if the cells is empty
				    //then traverse all the character from '1' to '9' check if they can be placed in empty cell
					for( char c ='1';c<='9';c++)
					{
						if(is_valid(i, j, board, c))
						{ 	
							//check if any of character is valid at (row, col)
							board[i][j]=c; //place the character
							if(solve(board)) return true;  //recur to check for other empty positions left
							
							board[i][j]='.'; //backtrack if that was not a valid configuration
						}
					}
                	return false;  //if none of characters(1 to 9) can be placed return empty
                }
                   
            }
        }
        return true; //return true if valid configuration was obtained
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
	{ 
		if(board.size()==0)return; //if board is empty then return
        solve(board); 
    }
};

// main function
int main()
{
	// Taking input
	vector<vector<char >> board;
	for(int i=0;i<9;i++)
	{
		vector<char > v;
		for(int j=0;j<9;j++)
		{
			char x;
			cin>>x;
			v.push_back(x);
		}
		board.push_back(v);
	}
	
	// creating object for soluton class
	Solution *obj = new Solution();
	obj->solveSudoku(board); // calling the function to solve the sudoku
	
	// print he splve sudoku board
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

