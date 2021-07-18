V = 4
INF = 99999
# pythonpapa
def floydWarshall(graph):
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    printSolution(dist)
# pythonpapa
def printSolution(dist):
    for i in range(V):
        for j in range(V):
            if(dist[i][j] == INF):
                print ("%7s" % ("INF"))
            else:
                print ("{}".format((dist[i][j])), end = " "),
            if j == V-1:
                print ("")
# Author : Abhishek Sharma
graph = [[0, 11, 1, 6],
        [11, 0, 7, 3],
        [1, 7, 0, 2],
        [6, 3, 2, 0]]
# javaman
floydWarshall(graph)


# Test Cases
# Input
0 11 1 6
11 0 7 3
1 7 0 2
6 3 2 0

# Output
0 6 1 3
6 0 5 3
1 5 0 2
3 3 2 0
