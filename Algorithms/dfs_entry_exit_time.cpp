
/*
Algorithm :
	We will color all vertices with the color 0, if we haven't visited them, with the color 1 if we visited them, and with the color 2, if we already exited the vertex.
	and at the time we assign any vertex color 1, at that time we update time_in 
	and at the time we assign any vertex color 2, at that time we update time_out
	In this way we get the time_in(entry time) and time_out(exit_time) of each vertex
*/

#include<bits/stdc++.h>
using namespace std;

// created three vector to store color, time_in, time_out of each vertex
vector<int > color(10,0), time_in(10,-1), time_out(10, -1);

// created variable dfs_timer and initialized to 0
int dfs_timer = 0;

// function created to find the entry and exit time each vertex and store it in vertex time_in and time_out
void dfs_entry_exit(vector<int > graph[ ], int n, int v)
{
//	cout<<"up "<<v<<endl;
	time_in[v] = dfs_timer++;
	color[v]=1;
	for(auto it : graph[v])
	{
		if(color[it]==0)
		dfs_entry_exit(graph,n,it);
	}
//	cout<<"down "<<v<<endl;
	color[v] = 2;
	time_out[v] = dfs_timer++;
}
int main()
{
	//we created graph with n vertex
	int n = 6;
	vector<int > graph[n];
	
	graph[0].push_back(1);
	graph[1].push_back(0);
	
	graph[0].push_back(2);
	graph[2].push_back(0);
	
	graph[1].push_back(4);
	graph[4].push_back(1);
	
	graph[2].push_back(4);
	graph[4].push_back(2);
	
	graph[2].push_back(3);
	graph[3].push_back(2);
	
	graph[3].push_back(5);
	graph[5].push_back(3);
	
	// called the funtion
	dfs_entry_exit(graph, n, 0);
	
	// printing the  output
	cout<<"\nVertex\tEntry_time\tExit_time\n";
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t   "<<time_in[i]<<"\t\t   "<<time_out[i]<<endl;
	}
	
	return 0;
} 
