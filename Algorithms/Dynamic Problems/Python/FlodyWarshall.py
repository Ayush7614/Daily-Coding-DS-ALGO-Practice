#Python3 mplementation of FloydWarshall Algorithm

#the below represents Number of Vertices in the main graph
v=4

"""Define infinity as the large
   enough value. This value will be 
   used for verticles not connected to each other """

INF=99999

#the function solves all pair shortest path via
# FloydWarshall Algorithm

def FloydWarshall(graph):
    
    """
    dist[][] will be the output
    matrix that will finally 
    have the shortest distances
    between every pair of vertices
    """
    dist=list(map(lambda i: list(map(lambda j:j,i)),graph))
    
    for k in range(v):
        
        for i in range(v):
            
            for j in range(v):
                
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
                
    printSolution(dist)
    
    
def printSolution(dist):
    
    print ("Following Matrix Shows the shortest distances between every pair of vertices")
    
    for i in range(v):
        
        for j in range(v):
            
            if dist[i][j]==INF:
                
                print( "%7s" % ("INF"),end=" ")
                
            else:
                
                print( "%7d" % (dist[i][j]),end=" ")
                
            if j==v-1:
                
                print()

graph=[[0  ,5  ,INF ,10 ]
      ,[INF,0  ,3  ,INF]
      ,[INF,INF,0  ,1  ]
      ,[INF,INF,INF,0  ]]


FloydWarshall(graph) 
