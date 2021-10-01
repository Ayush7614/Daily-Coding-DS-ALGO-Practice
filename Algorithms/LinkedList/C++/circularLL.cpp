// C++ program to check if linked list is circular
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

/* This function returns true if given linked
list is circular, else false. */
bool isCircularLL(struct Node *head)
{
	
	if (head == NULL)
	return true;

	
	struct Node *node = head->next;

	
	while (node != NULL && node != head)
	node = node->next;

	
	return (node == head);
}


Node *newNode(int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}


int main()
{
	
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	isCircularLL(head)? cout << "Yes\n" :
					cout << "No\n" ;

	
	head->next->next->next->next = head;

	isCircularLL(head)? cout << "Yes\n" :
					cout << "No\n" ;

	return 0;
}
