# Node structure
class Node:
	
	def __init__(self, data):
		self.data = data
		self.next = None
	
def newNode(data):
	node = Node(data)
	return node

# Function to find the luckiest person
def alivesol( Num):
	if (Num == 1):
		return 1

	# Create a single node circular
	# linked list.
	last = newNode(1)
	last.next = last
	
	for i in range(2, Num + 1):	
		temp = newNode(i)
		temp.next = last.next	
		last.next = temp 
		last = temp 	
	
	# Starting from first soldier.
	curr = last.next 

	# condition for evaluating the existence
	# of single soldier who is not killed.
	temp = None
	
	while (curr.next != curr):	
		temp = curr 
		curr = curr.next 
		temp.next = curr.next 

		# deleting soldier from the circular
		# list who is killed in the fight.
		del curr 
		temp = temp.next 
		curr = temp 

	# Returning the Luckiest soldier who
	# remains alive.
	res = temp.data 
	del temp 	
	return res 
	
#Input Code

N = int(input())
print(alivesol(N))


'''
Example:
Input1: 
N=5

Output1:
3

Explanation1:
N = 5 
Soldier 1 2 3 4 5 (5 soldiers) 
In first go 1 3 5 (remains) as 2 and 4 killed by 1 and 3. 
In second go 3 as 5 killed 1 and 3rd kill 5 soldier 3 remains alive.
----------------------------------------------------------------------
Input2: 
N=100

Output2:
73

Explanation2:
N = 10 
Soldiers 1 2 3 4 5 6 7 8 9 10 (10 soldiers) 
In first 1 3 5 7 9 as 2 4 6 8 10 were killed by 1 3 5 7 and 9. 
In second 1 5 9 as 9 kill 1 and in turn 5 kill 9th soldier. 
In third 5 5th soldiers remain alive
'''

