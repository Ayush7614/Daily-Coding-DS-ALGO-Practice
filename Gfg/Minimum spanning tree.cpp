//Link of the Question:https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
//QUESTION STATEMENT:
/*Given a weighted, undirected and connected graph of V vertices and E edges.
 The task is to find the sum of weights of the edges of the Minimum Spanning Tree.*/

 //SOLUTION:
#include<bits/stdc++.h>
using namespace std;
class DSU
{
    int*parent;
    int*rank;
    public:
    DSU(int n)
    {
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i)//find function to check the parent
    {
        if(parent[i]==-1)
        return i;
        return parent[i]=find(parent[i]);
        //->
    }
    void unite(int x,int y)//union func to make the common parent
    {
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])//if s1 is bigger
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
                rank[s1]=0;
            }
            else//if s2 is bigger
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
                rank[s2]=0;
            }
        }
    }
};
class graph
{
    vector<vector<int>> edgelist;
    int v;
    public:
    graph(int v)
    {
        this->v=v;
    }
    void addedge(int x,int y,int w)
    {
        edgelist.push_back({w,x,y});
    }
    int kruskal_mst()
    {
        sort(edgelist.begin(),edgelist.end());
        DSU s(v);
        int ans=0;
        for(auto edge:edgelist)
        {
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(s.find(x)!=s.find(y))//if belong to diff parent, union
            {
                s.unite(x,y);
                ans+=w;
            }
        }
        return ans;
    }
};
int main()
{
    /*graph g(4);
    g.addedge(0,1,1);
    g.addedge(1,3,3);
    g.addedge(3,2,4);
    g.addedge(2,0,2);
    g.addedge(0,3,2);
    g.addedge(1,2,2);*/
    int n,m;
    cin>>n>>m;//inputing vertices and edges
    graph g(n+1);//making a graph
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.addedge(x,y,w);
    }
    cout<<g.kruskal_mst()<<endl; //printing minimum cost of the spanning tree 
    return 0; 
}