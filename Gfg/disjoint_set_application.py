

                           
               






class DisjSet:
	def __init__(self, n):
		
		self.rank = [1] * n
		self.parent = [i for i in range(n)]


	
	def find(self, x):
		
		
		if (self.parent[x] != x):
			
			
			self.parent[x] = self.find(self.parent[x])
			
		

		return self.parent[x]


	
	def Union(self, x, y):
		
		
		xset = self.find(x)
		yset = self.find(y)

		
		if xset == yset:
			return

		
		if self.rank[xset] < self.rank[yset]:
			self.parent[xset] = yset

		elif self.rank[xset] > self.rank[yset]:
			self.parent[yset] = xset

		
		else:
			self.parent[yset] = xset
			self.rank[xset] = self.rank[xset] + 1

obj = DisjSet(5)
obj.Union(0, 2)
obj.Union(4, 2)
obj.Union(3, 1)
if obj.find(4) == obj.find(0):
	print('Yes')
else:
	print('No')
if obj.find(1) == obj.find(0):
	print('Yes')
else:
	print('No')
	
	
	/*
We are given 10 people,
a, b, c, d, e, f, g, h, i, j

Following are relationships to be added.
a <-> b  
b <-> d
c <-> f
c <-> i
j <-> e
g <-> j
Whether a is a friend of d
or not.

We basically need to create following 4 groups:
G1 = {a, b, d}
G2 = {c, f, i}
G3 = {e, g, j}
G4 = {h}

*/

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	



