# Function to find all pairs that are a mirror of each other
def findPairs(pairs):
 
    # create an empty set of strings
    s = set()
 
    # do for each pair
    for (x, y) in pairs:
 
        # insert the current pair `(x, y)` into the set
        s.add((x, y))
 
        # if mirror pair `(y, x)` is seen before, print the pairs
        if (y, x) in s:
            print((x, y), "|", (y, x))
 
 
if __name__ == '__main__':
 
    pairs = [(3, 4), (1, 2), (5, 2), (7, 10), (4, 3), (2, 5)]
    findPairs(pairs)