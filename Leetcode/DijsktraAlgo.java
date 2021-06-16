// this program is the solution to the question https://www.pepcoding.com/resources/online-java-foundation/graphs/shortest-path-in-weights-official/ojquestion
// dijsktra algorithm
import java.io.*;
import java.util.*;

// construction of the graph
public class Main {
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }
   
   public static class Pair implements Comparable<Pair>{
       int vtx ;
       String path ;
       int wt ;
       
       Pair(int vtx,String path,int wt){
           this.vtx=vtx ;
           this.path=path ;
           this.wt=wt ;
       }
       
       public int compareTo(Pair other){
           return this.wt-other.wt ;
       }
       
   }
// main function
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt));
         graph[v2].add(new Edge(v2, v1, wt));
      }

      int src = Integer.parseInt(br.readLine());
      // this function prints shortest path to each city (in terms of kms) from the source city along 
    // with the total distance on path from source to destinations.
      shortPath(graph,src) ;
      
   }
   
   public static void shortPath(ArrayList<Edge>[] graph,int src){
       boolean []flag=new boolean[graph.length] ;
       
         PriorityQueue<Pair> pq = new PriorityQueue<>();
         pq.add(new Pair(src,""+src,0)) ;
         
         while(pq.size()>0){
             Pair top=pq.remove() ;
             if(flag[top.vtx]) continue ;
             flag[top.vtx]=true ;
             System.out.println(top.vtx+" via "+top.path+" @ "+top.wt) ;
             for(Edge e:graph[top.vtx]){
                 if(!flag[e.nbr]) pq.add(new Pair(e.nbr,top.path+e.nbr,top.wt+e.wt)) ;
             }
             
         }
         
         
         
   }
}
