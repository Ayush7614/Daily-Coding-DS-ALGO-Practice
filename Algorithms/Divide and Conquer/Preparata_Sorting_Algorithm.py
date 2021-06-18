'''

Steps for Preparata's Sorting ALgorithm are : 

-> If N is a small constant we will sort the keys using any algorithm and quit
-> Partition the given N keys into log N parts with N/(log N) keys in each part.
-> Now Sort each part recursively and separately in parallel, assigning N processors to each part. Let S1, S2, …, Slog N be the sorted sequences.
-> After that Merge Si with Sj for 1< i, j < log N in parallel. This can be done by allocating N/(log N) processors to each pair(i, j). That is, using N*log N processors, this step can be accomplished in O(log(log N)) time with the algorithm. As a by-product of this merging step, the rank is computed of each key in each one of the Si‘s(1 < i < log N).
-> Now Allocate log N processors to compute the rank of each key in the original input. This is done in parallel for all the keys by adding the log N ranks computed (for each key) in step 2. This can be done in O(log(log N)) time using the prefix computation algorithm.
-> And Finally, the keys are written in the order of their ranks.



'''
# a time-optimal parallel algorithm
  
  
class func:
    def __init__(self, x, y):
        self.x = x
        self.y = y
  
# Function to find the left index of
# the given set of points
def Left_index(points):
      
    # Finding the point on plane
    minn = 0
      
    # Traverse the given points
    for i in range(1, len(points)):
        
          # Update the value of minn
        if points[i].x < points[minn].x:
            minn = i
        elif points[i].x == points[minn].x:
            if points[i].y > points[minn].y:
                minn = i
                  
    # Return the value of min
    return minn
  
# Function to perform the parallel
# process in the preparata's algorithm
# according to the value of p, q, r
def parallel(p, q, r):
  
    # For the three-dimensional
    val = (q.y - p.y) * (r.x - q.x) - \
        (q.x - p.x) * (r.y - q.y)
  
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2
  
# Function to perform the parallel
# process in the preparata's algorithm
def preparata(points, n):
  
    # There must be at least 3 points
    if n < 3:
        return
  
    # Find the leftmost point
    l = Left_index(points)
  
    pre = []
  
    p = l
    q = 0
    while(True):
  
        # Add current point to result
        pre.append(p)
  
        q = (p + 1) % n
  
        for i in range(n):
  
            # If i is more counterclockwise
            # than current q, then update q
            if(parallel(points[p],
                        points[i], points[q]) == 2):
                q = i
  
        p = q
  
        # While it doesn't come to first point
        if(p == l):
            break
  
    # Print Result
    for each in pre:
        print(points[each].x, points[each].y)


#Code 
  
  
algo = []
algo.append(func(0, 3))
algo.append(func(2, 2))
algo.append(func(1, 1))
algo.append(func(2, 1))
algo.append(func(3, 0))
algo.append(func(0, 0))
algo.append(func(3, 3))
  
# Function Call
preparata(algo, len(algo))  2
