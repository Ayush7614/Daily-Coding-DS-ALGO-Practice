// Rat In A Maze
// Problem Statement
/*
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.

Input Format:
The first line of input contains an integer 'N' representing the dimension of the maze.
The next 'N' lines of input contain 'N' space-separated integers representing the type of the cell.

Output Format :
For each test case, return the path from the start position to the destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.
Output for every test case will be printed in a separate line.
*/


// Solution to the Problem
#include<bits/stdc++.h>
using namespace std;

void print(int** arr, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << arr[i][j] << " ";
		}
	}
    cout<<endl;
}

bool checker(int maze[][20] ,int **arr, int row, int col, int n){
    if(row<0 || col<0){
        return false;
    }
    if(row>n-1 || col>n-1){
        return false;
    }
    int k = maze[row][col];
    if(k==1 && arr[row][col]==0){
        return true;
    }
    return false;
}

void placer(int maze[][20] , int** arr, int row, int col, int n){
	if (row==(n-1) && col==(n-1)){
		print(arr, n);
		return;
	}
	int j = col;
    while(j<col+1){
        // For Right Check
        if(checker(maze, arr, row, j+1, n))
        {
            arr[row][j+1] = 1;
            placer(maze, arr, row, j+1, n);
            arr[row][j+1] = 0;
        }
        // For Left Check
        if(checker(maze, arr, row, j-1, n)){
            arr[row][j-1] = 1;
            placer(maze, arr, row, j-1, n);
            arr[row][j-1] = 0;
        }
        // For Down Check
        if(checker(maze, arr, row+1, j, n)){
            arr[row+1][j] = 1;
            placer(maze, arr, row+1, j, n);
            arr[row+1][j] = 0;
        }
        // For Up Check
        if(checker(maze, arr, row-1, j, n)){
            arr[row-1][j] = 1;
            placer(maze, arr, row-1, j, n);
            arr[row-1][j] = 0;
        }
       j++;
    }
    return;
}

void ratInAMaze(int maze[][20], int n){
    int** arr = new int* [n];
    for (int i=0; i<n; i++){
        arr[i] = new int[n];
        for (int j=0; j<n; j++){
			arr[i][j] = 0;
		}
	}
    arr[0][0]=1;
    placer(maze, arr, 0, 0, n);  
    for(int i=0; i<n; i++){
        delete[]arr[i];
    }
    delete[]arr;
}

// Main Function
int main(){
    int n;
    cin >> n ;
    int maze[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maze[i][j];
        }		
    }
    ratInAMaze(maze, n);
}

// Test Cases
/*
Exapmple 1:
Input:
3
1 0 1
1 0 1
1 1 1
Output:
1 0 0 1 0 0 1 1 1

Exapmple 2:
Input:
4
1 1 1 1
1 0 0 1
1 0 1 1
1 1 1 1
Output:
1 1 1 1 0 0 0 1 0 0 1 1 0 0 1 1 
1 1 1 1 0 0 0 1 0 0 0 1 0 0 0 1 
1 0 0 0 1 0 0 0 1 0 0 0 1 1 1 1 
1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 1 
*/