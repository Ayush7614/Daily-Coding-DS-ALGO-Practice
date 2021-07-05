/*
Idea behind solution : We want to see is there a path from one end to another end along the width.
We first convert the given data to the graph(possibly it will become disconnected graph). 
Consider the soldiers as the nodes and we will add an edge between two soldiers if there 
range of view has some intersection part or if they are just joining. Check every possible pair of point(Soldiers). 
Find distance b/w two i.e If(x1 - x2)^2 + (y1 - y2)^2 <= 200 * 200 (100(from soldier1) + 100(from soldier2)). Then add the edge.
After this we will use bfs to find this path from one end of the canoyn to other end. If there exist then there is no way to escape
else there is a way to escape always. Line 35 to 39 in bfs() what we are doing is we are pushing those soldiers whose y coordinates are
atmost 100 unit and there view intersect with the bottom part(As we are starting our path search from bottom to top so we push these 
or one can also push from the top and search the path to the bottom). Only thing different is we are
returning true (line 51) because we reach at the soldier who is atmost 100 unit far from the w(width line at the top) and this ensure that there
is path, else if this is never possible then at last we have return (false).

Input format:
The first line contains three integers L, W, and N – the length and the width of the canyon, and the number of soldiers, respectively. 
Each of the following N lines contains a pair of integers Xi and Yi – the coordinates of i-th soldier in the canyon (0 ≤ Xi ≤ L, 0 ≤ Yi ≤ W). 
The coordinates are given in meters, relative to the canyon: the southwestern corner of the canyon has coordinates (0, 0), and the northeastern corner 
of the canyon has coordinates (L,W), as seen in the picture above. Note that passing the canyon may start at coordinate (0,ys) for any 0 ≤ ys ≤ W and 
end at coordinate (L,ye) for any 0 &\le; ye ≤ W. Neither ys nor ye need to be integer.

Output format:
Output a single integer: 0 if the prisoners can escape, 1 if they cannot.

Input:
500 300 6
250 0
100 300
200 150
300 150
400 300
250 300

Output:
1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

map<int, pair<int, int>> coordinates;
vector<vector<int> >g;

int l, w, n;
	
bool distance(int i, int j) {
	int Y = coordinates[i].second - coordinates[j].second;
	int X = coordinates[i].first - coordinates[j].first;
	X *= X;
	Y *= Y;
	int atMax = 200 * 200;
	return (X + Y <= atMax);
}
bool bfs() {
	queue<int> q;
	vector<int> vis(n + 1, 0);

	for(int i = 0; i < n; ++i) {
		if(coordinates[i].second <= 100) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v: g[u]) {
			if(!vis[v]) {
				if(abs(w - coordinates[v].second) <= 100)
					return true;
				else {
					vis[v] = 1;
					q.push(v);
				}
			}
 		}
	}
	return false;
}

int32_t main() {

	cin >> l >> w >> n;
	g = vector<vector<int> >(n);	
	
	for(int i = 0; i < n; ++i) {
		cin >> coordinates[i].first >> coordinates[i].second;
	}

	for(int i = 0; i < n - 1; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(distance(i, j)) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	cout << (bfs() ? "1\n" : "0\n");
	return 0;
}
