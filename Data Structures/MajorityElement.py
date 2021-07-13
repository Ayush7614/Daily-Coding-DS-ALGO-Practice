# Program for finding out majority element in an array
# Using Moore’s Voting Algorithm

def findCandidate(A):
	maj_index = 0
	count = 1
	for i in range(len(A)):
		if A[maj_index] == A[i]:
			count += 1
		else:
			count -= 1
		if count == 0:
			maj_index = i
			count = 1
	return A[maj_index]

# Function to check if the candidate occurs more than n/2 times

def isMajority(A, cand):
	count = 0
	for i in range(len(A)):
		if A[i] == cand:
			count += 1
	if count > len(A)/2:
		return True
	else:
		return False

def printMajority(A):
	cand = findCandidate(A)
	if isMajority(A, cand) == True:
		print(cand)
	else:
		print("No Majority Element")


# Driver code
A = [1, 3, 3, 3, 2]
printMajority(A)


# Output
# 3

# Time Complexity: O(n)
# Space Complexity: O(1)
