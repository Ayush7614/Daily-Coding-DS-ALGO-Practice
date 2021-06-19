//Disjoint Set - Implementation
#include<bits/stdc++.h>
using namespace std;
class disjointset
{
	int *rank,*parent,n;
	public:
		
	// Constructor to create and initialize sets of n items 
	disjointset(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		for(int i=0;i<n;i++)
		{
			rank[i] = 0;
		}
		dsmakeset();
	}
	
	// Creates n single item sets 
	void dsmakeset()
	{
//		cout<<"Printing the initial Parent array :\n";
		for(int i=0;i<n;i++)
		{
			parent[i] = i;
//			cout<<parent[i]<<" ";
		}
//		cout<<endl;
	}
	
	// display methods -----------------------------------------------------------------------------
	void display_parent()
	{
		cout<<"Printing the Parent array :\n";
		for(int i=0;i<n;i++)
		{
			cout<<parent[i]<<" ";
		}
		cout<<endl;
	}
	void display_rank()
	{
		cout<<"Printing the Rank array :\n";
		for(int i=0;i<n;i++)
		{
			cout<<rank[i]<<" ";
		}
		cout<<endl;
	}
	//----------------------------------------------------------------------------------------------
	
	// find method ---------------------------------------------------------------------------------
	// Finds set of given item x     ------------- This is normal find funtion, without any improvements
	int dsfind(int x) // This is normal find funtion, without any improvements
	{
		// Finds the representative of the set that x is an element of
		if(parent[x] != x)
		{
			// if x is not the parent of itself 
            // Then x is not the representative of 
            // his set,
            parent[x] = dsfind(parent[x]);
            // so we recursively call Find on its parent 
            // and move i's node directly under the 
            // representative of this set
		}
		return parent[x];
	}
	/*
	int dsfind(int x) // This is find funtion, with improvements called path compression
	{
		if(parent[x] == x)
		{
            return x;
		}
		else
		{
			// Recursively find the representative.
	        int result = dsfind(parent[x]);
	
	        // We cache the result by moving i’s node 
	        // directly under the representative of this
	        // set
	        parent[x] = result;
	       
	        // And then we return the result
	        return result;
		}
	}
	*/
	// ------------------------------------------------------------------------------------
	
	// union method ----------------------------------------------------------------------------
	void dsunion(int x,int y) // this is simple union without any improvements
	{
		int xset = dsfind(x);
		int yset = dsfind(y);
		if(xset == yset)
		return ;
		parent[xset] = yset; // or parent[yset] = xset;
	}
	
	/*
	ll dsunion(ll parent[], ll size[ ], ll x, ll y) // union by size
	{
		ll x1 = find(parent,x);
		ll y1 = find(parent,y);
		if(size[x1] < size[y1])
	    {
			parent[x1] = y1;
			size[y1] += size[x1];
	    }
	    else
	    {
			parent[y1] = x1;
			size[x1] += size[y1];
	    }
	}
	*/
	
	/*
	void dsunion(int x,int y) // this is basically union by rank
	{
		// Find current sets of x and y 
		int xset = dsfind(x);
		int yset = dsfind(y);
		//if they are already in same set
		if(xset == yset)
		return ;
		// Put smaller ranked item under bigger ranked item if ranks are different 
		if(rank[xset] < rank[yset])
		parent[xset] = yset;
		else if(rank[xset] > rank[yset])
		parent[yset] = xset;
		// If ranks are same, then increment rank.
		else//either of both can be parent of other one's when ranks are same
		{
			parent[yset] = xset;
			rank[xset] = rank[xset] + 1;
		}
	}
	*/
	//--------------------------------------------------------------------------------------------
	
};
int main()
{
	disjointset obj(5);
	
	obj.dsunion(0,2);
	obj.dsunion(4,2);
	obj.dsunion(3,1);
	
	if(obj.dsfind(4) == obj.dsfind(0))
	cout<<"Both 4 and 0 are in same subset.\n";
	else
	cout<<"Both 4 and 0 are in different subset.\n";
	
	if(obj.dsfind(1) == obj.dsfind(0))
	cout<<"Both 4 and 0 are in same subset.\n";
	else
	cout<<"Both 4 and 0 are in different subset.\n";
	return 0;
}
