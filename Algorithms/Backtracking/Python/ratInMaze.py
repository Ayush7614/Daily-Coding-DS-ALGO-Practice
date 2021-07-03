# Python3 program to solve Rat in a Maze
# problem using backracking

# Maze size
N = 4

#A utility function to print solution matrix sol
def printSolution( sol ):
	
	for i in sol:
		for j in i:
			print(str(j) + " ", end ="")
		print("")

# A utility function to check if x, y is valid

def isSafe( maze, x, y ):
	
	if x >= 0 and x < N and y >= 0 and y < N and maze[x][y] == 1:
		return True
	
	return False

def solveMaze( maze ):
	
	sol = [ [ 0 for j in range(4) ] for i in range(4) ]
	
	if solveMazeUtil(maze, 0, 0, sol) == False:
		print("Solution doesn't exist")
		return False
	
	printSolution(sol)
	return True
	
# A recursive utility function to solve Maze problem
def solveMazeUtil(maze, x, y, sol):
	
	if x == N - 1 and y == N - 1 and maze[x][y]== 1:
		sol[x][y] = 1
		return True
		
	# Check if maze[x][y] is valid
	if isSafe(maze, x, y) == True:
		# Check if the current block is already part of solution path.
		if sol[x][y] == 1:
			return False
		
		# mark x, y as part of solution path
		sol[x][y] = 1
		
		
		if solveMazeUtil(maze, x + 1, y, sol) == True:
			return True
			
		if solveMazeUtil(maze, x, y + 1, sol) == True:
			return True
		
	
		if solveMazeUtil(maze, x - 1, y, sol) == True:
			return True
		
		if solveMazeUtil(maze, x, y - 1, sol) == True:
			return True
		
		# If none of the above movements work then
		# BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0
		return False

if __name__ == "__main__":
	# Initialising the maze
	maze = [ [1, 0, 0, 0],
			[1, 1, 0, 1],
			[0, 1, 0, 0],
			[1, 1, 1, 1],
			]
			
	solveMaze(maze)


"""

OUTPUT: 
1 -> is the path for rat 
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
"""