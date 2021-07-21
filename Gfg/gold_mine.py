# Desccription Gold Mine Algorithm
# Given a gold mine of n*m dimensions.
# Each field in this mine contains a positive integer which is the amount of gold in tons.
# Initially the miner is at first column but can be at any row.
# He can move only (right->,right up /,right down\) that is from a given cell,
# the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right.
# The program calculates the maximum amount of gold he can collect.

def max_gold(gold,m,n):
    # Table for storing intermediate results and initializing all cells to 0.
    # The first row of goldMineTable gives the maximum gold that the miner can collect when starts that row
    goldTable = [[0 for i in range(n)]
                        for j in range(m)]
 
    for col in range(n-1, -1, -1):
        for row in range(m):
 
            # Gold collected on going to the cell on the rigth(->)
            if (col == n-1):
                right = 0
            else:
                right = goldTable[row][col+1]
 
            # Gold collected on going to the cell to right up (/)
            if (row == 0 or col == n-1):
                right_up = 0
            else:
                right_up = goldTable[row-1][col+1]
 
            # Gold collected on going to the cell to right down (\)
            if (row == m-1 or col == n-1):
                right_down = 0
            else:
                right_down = goldTable[row+1][col+1]
 
            # Max gold collected from taking either of the above 3 paths
            goldTable[row][col] = gold[row][col] + max(right, right_up, right_down)
                                                            
    # The max amount of gold collected will be the max value in first column of all rows
    res = goldTable[0][0]
    for i in range(1, m):
        res = max(res, goldTable[i][0])
 
    return res
    

# Main function
def main():
    

    m = int(input('Enter number of rows : '))
    n = int(input('Enter number of columns : '))

    print('Enter gold values')
    gold_mat = [[int(j) for j in input().split()]for i in range(n)]

    print('GOLD MINE MATRIX :')
    for i in range(len(gold_mat)):
        for j in range(len(gold_mat[i])):
            print(gold_mat[i][j],end=" ")
        print()
    
    # To calculate maximum gold 
    print('The maximum amount of gold collected : ',max_gold(gold_mat,m,n))

# To check if the file contains the main function and then calling the main function
if __name__ == '__main__':
    main()

# COMPLEXITY:
# Time Complexity :O(m*n) 
# Space Complexity :O(m*n)

# OUTPUT
            # Input  : 
                # gold_mat = 10 9 2 30
                          #  15 12 3 40
                          #  11 8 4 50
            # Output : 
                # Maximum amount of gold collected : 81