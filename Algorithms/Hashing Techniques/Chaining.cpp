#include <iostream>
using namespace std;

// Linked List node
class Node{

public:
	int data;
	Node* next;

};

// Hash Table
class HashTable{

public:
	Node** HT;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	~HashTable();

};

HashTable::HashTable(){

    //creating a new Hash Table of size 10
	HT=new Node* [10];
	for(int i=0;i<10;i++){
		HT[i]=NULL;
	}
}

//return last digit of key
int HashTable::hash(int key) {
	return key%10;
}

//inserting key
void HashTable::Insert(int key) {

	int hIdx=hash(key);

	Node* t=new Node;
	t->data=key;
	t->next=NULL;

	//Case: if the given position is empty
	if(HT[hIdx]==NULL){
		HT[hIdx]=t;
	} 
    
    //else look for a free space
    else{
		Node* p=HT[hIdx];
		Node *q=HT[hIdx];     //q is a tailing pointer of p

		while(p&&p->data < key){
			q=p;
			p=p->next;
		}

		if(q==HT[hIdx]){
			t->next=HT[hIdx];
			HT[hIdx]=t;
		} 

        else{
			t->next=q->next;
			q->next=t;
		}
	}
}

int HashTable::Search(int key) {

	int hIdx=hash(key);
	Node* p=HT[hIdx];
    
    //continue the loop till p becomes NULL
	while(p){
		if(p->data==key){      //if key is found, return
			return p->data;
		}
		p=p->next;
	}

	return -1;
}

//deleting the extra memory consumed
HashTable::~HashTable() {

	for(int i=0; i<10; i++){
		Node* p=HT[i];

		while(HT[i]){
			HT[i]=HT[i]->next;
			delete p;
			p=HT[i];
		}
	}

	delete []HT;
}


/* Driver Code */
int main() {

	//creating a HashTable with an array
	int A[]= {16, 12, 25, 39, 6, 122, 5, 68, 75};
	HashTable H;
    
    //inserting the data into HashTable
	for (int i=0; i<9; i++){
		H.Insert(A[i]);
	}

    //Case for Successful Search
	cout<<"Successful Search"<<"\n";
	int key=6;
	int value=H.Search(key);
	cout<<"Key: "<<key<<", Value: "<<value<<"\n";

    //Case for Unsuccessful Search, value=-1 if not found
	cout<<"Unsuccessful Search"<<"\n";
	key=95;
	value=H.Search(key);
	cout<<"Key: "<<key<<", Value: "<<value<<"\n";

	return 0;
}