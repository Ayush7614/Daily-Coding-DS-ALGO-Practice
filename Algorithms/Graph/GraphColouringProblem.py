class Graph:

    def __init__(self, edges, N):
        self.adj = [[] for _ in range(N)]
 
        for (src, dest) in edges:
            self.adj[src].append(dest)
            self.adj[dest].append(src)
 

def colorGraph(graph):
 
    res = {}
    for u in range(N):
 
        assigned = set([res.get(i) for i in graph.adj[u] if i in res])
 
        color = 1
        for c in assigned:
            if color != c:
                break
            color = color + 1
 
        res[u] = color
 
    for v in range(N):
        print("Color assigned to vertex", v, "is", colors[res[v]])
 
 
# Greedy coloring of a graph
#Input Code
if __name__ == '__main__':
 
    colors = ["", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
            "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"]
 
    
 
    # total number of nodes in the graph
    M=int(input())
    edges=[]
    for i in range(M):
        edges[i]=tuple(map(int,input().split()))
    
    # build a graph from the given edges
    graph = Graph(edges, N)
    N=int(input())
    # color graph using the greedy algorithm
    colorGraph(graph)


'''
Example:
Input:
M=8
edges = [(0, 1), (0, 4), (0, 5), (4, 5), (1, 4), (1, 3), (2, 3), (2, 4)]
N = 6

graph = Graph(edges, N)

colorGraph(graph)


Output:
The color assigned to vertex 0 is BLUE
The color assigned to vertex 1 is GREEN
The color assigned to vertex 2 is BLUE
The color assigned to vertex 3 is RED
The color assigned to vertex 4 is RED
The color assigned to vertex 5 is GREEN
'''