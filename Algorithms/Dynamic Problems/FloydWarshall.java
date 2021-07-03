// Floyd War Shall using Java
// Author : Abhishek Sharma

import java.util.*;
import java.lang.*;
import java.io.*;


class Solution
{
    final static int INF = 99999, V = 4;

    void floydWarshall(int graph[][])
    {
        int dist[][] = new int[V][V];
        int i, j, k;
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];
        for (k = 0; k < V; k++)
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printSolution(dist);
    }

    void printSolution(int dist[][])
    {
        for (int i=0; i<V; ++i)
        {
            for (int j=0; j<V; ++j)
            {
                if (dist[i][j]==INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main (String[] args)
    {
        int graph[][] = {{0, 11, 1, 6},
                        {11, 0, 7, 3},
                        {1, 7, 0, 2},
                        {6, 3, 2, 0}};
        Solution a = new Solution();

        a.floydWarshall(graph);
    }
}


// Test Cases
// Input
0 11 1 6
11 0 7 3
1 7 0 2
6 3 2 0

// Output
0 6 1 3
6 0 5 3
1 5 0 2
3 3 2 0
