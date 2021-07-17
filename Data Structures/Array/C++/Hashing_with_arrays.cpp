#include<iostream>
#include<stdlib.h>
using namespace std;
const int TABLE_SIZE=10;		// INITIALIZING THE HASH TABLE SIZE TO 10
								// YOU CAN CHANGE TO YOUR DESIRED VALUE
// HashEntry Class Declaration
class HashEntry
{
	public:
		int key;
		int value;
		HashEntry(int k, int v)		// PARAMETERIZED CONSTRUCTOR FOR INITIALIZATION
		{
			key = k;
			value = v; 
		}
};

class HashMap
{
	private:
		HashEntry **table;
		int neverUsed[TABLE_SIZE];
	public:
		HashMap()		//CREATING A HASH TABLE 
		{
			table = new HashEntry * [TABLE_SIZE]; 
			for (int i = 0; i< TABLE_SIZE; i++)
			{
				table[i] = NULL;		//USING ARRAY FOR HASHMAP
				neverUsed[i]=1; 	
			}
		}

		int HashFunc(int key) 				// HASH FUNCTION USING WHICH
		{
			return key % TABLE_SIZE; 
		}

		void Insert(int key, int value) 	//METHOD FOR INSERTING KEY, VALUE PAIR IN
		{									// HASH TABLE
			int hash = HashFunc(key);
			int tmp=hash;
			while (table[hash] != NULL && table[hash]->key != key) 
			{
				hash = HashFunc(hash + 1); 
				if(hash==tmp)					//CHECKING IF THE HASH TABLE
				{								// IS EMPTY OR NOT
					cout<<"Table full\n";
					return; 
				}
			}
			if (table[hash] != NULL)
				delete table[hash];
			table[hash] = new HashEntry(key, value); 
			neverUsed[hash]=0;
		}

		int Search(int key) 				//METHOD TO SEARCH A HASH VALUE USING ITS KEY
		{
			int hash = HashFunc(key); 
			int tmp=hash;
			while (!neverUsed[hash]) 
			{
				if(table[hash]==NULL || table[hash]->key != key) 
					hash = HashFunc(hash + 1);
				else
					break;
				if(hash==tmp) 
					return -1;
			}
			if (neverUsed[hash])		//IF THE KEY VALUE GIVEN DOESN'T CONTAIN A VALUE THEN
				return -1; 				// -1 IS RETURNED
			else
				return table[hash]->value;
		}

		void Remove(int key)		// METHOD TO REMOVE A HASH VALUE FROM THE GIVEN KEY POSITION
		{
			int hash = HashFunc(key); 
			int tmp=hash;
			int f=0;
			while (!neverUsed[hash]) 
			{
				if(table[hash]==NULL || table[hash]->key != key) 
					hash = HashFunc(hash + 1);
				else
					break;
				if(hash==tmp) 		//CHECKING IF THE VALUE TO BE DELETED IS THERE IN TABLE
				{					// OR NOT
					f=1;
					break; 
				}
			}
			if (neverUsed[hash]||f) 
			{
				cout<<"Element Not Found at key : "<< key <<endl; 
			}
			else 
			{
				delete table[hash]; 
				table[hash]=NULL; 
				cout<<"Element Deleted"<<endl;
			}
		}

		void display() 
		{
			for(int i=0;i<TABLE_SIZE;i++) 
			{
				if(table[i]!=NULL) 
					cout<<"["<<i<<"]"<<"("<<table[i]->key<<","<<table[i]->value<<")  ";
				else
					cout<<"["<<i<<"]"<<"( )  ";
			}
			cout<<"\n";
		}
		
		~HashMap() 		//Destructor TO FREE THE HASHTABLE MEMORY AFTER USE
		{
			for (int i = 0; i < TABLE_SIZE; i++) 
				if (table[i] != NULL)
					delete table[i];
			delete[] table;
		}
};

int main()
{
	HashMap obj;
	int key, value; 
	int choice; 			//ASKING USER CHOICE TO PERFORM OPERATIONS ON HASH TABLE
	while (1)
	{
		cout<<"\n----------------------"<<endl; 
		cout<<"Operations on Hash Table"<<endl; 
		cout<<"----------------------"<<endl; 
		cout<<"1.Insert element into the table"<<endl; 
		cout<<"2.Search element from the key"<<endl; 
		cout<<"3.Delete element at a key"<<endl; 
		cout<<"4.Display"<<endl; 
		cout<<"5.Exit"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"\nEnter element to be inserted: ";
					cin>>value;
					cout<<"Enter key at which element to be inserted: "; 
					cin>>key;
					obj.Insert(key, value);
					break; 
			case 2:
					cout<<"\nEnter key of the element to be searched: "; 
					cin>>key;
					if (obj.Search(key) == -1)
						cout<<"No element found at key: "<<key<<endl;
					else
					{
						cout<<"Element at key: "<<key<<" is ";
						cout<<obj.Search(key)<<endl;
					}
					break;
			case 3:
					cout<<"\nEnter key of the element to be deleted: "; 
					cin>>key;
					obj.Remove(key);
					break;
			case 4:
					cout<<"\n";
					obj.display();
					break; 
			case 5:
					exit(1);
			default:
					cout<<"\nEnter correct option\n";
		}
	}
	return 0;
}