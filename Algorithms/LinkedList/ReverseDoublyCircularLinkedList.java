// Java implementation to reverse a
// doubly circular linked list
class GFG
{

// structure of a node of linked list
static class Node
{
	int data;
	Node next, prev;
};

// function to create and return a new node
static Node getNode(int data)
{
	Node newNode = new Node();
	newNode.data = data;
	return newNode;
}

// Function to insert at the end
static Node insertEnd(Node head, Node new_node)
{
	// If the list is empty, create a single node
	// circular and doubly list
	if (head == null)
	{
		new_node.next = new_node.prev = new_node;
		head = new_node;
		return head;
	}

	// If list is not empty

	// Find last node /
	Node last = (head).prev;

	// Start is going to be next of new_node
	new_node.next = head;

	// Make new node previous of start
	(head).prev = new_node;

	// Make last previous of new node
	new_node.prev = last;

	// Make new node next of old last
	last.next = new_node;
	return head;
}

// Utility function to reverse a
// doubly circular linked list
static Node reverse(Node head)
{
	if (head==null)
		return null;

	// Initialize a new head pointer
	Node new_head = null;

	// get pointer to the the last node
	Node last = head.prev;

	// set 'curr' to last node
	Node curr = last, prev;

	// traverse list in backward direction
	while (curr.prev != last)
	{
		prev = curr.prev;

		// insert 'curr' at the end of the list
		// starting with the 'new_head' pointer
		new_head=insertEnd(new_head, curr);
		curr = prev;
	}
	new_head=insertEnd(new_head, curr);

	// head pointer of the reversed list
	return new_head;
}

// function to display a doubly circular list in
// forward and backward direction
static void display(Node head)
{
	if (head==null)
		return;

	Node temp = head;

	System.out.print( "Forward direction: ");
	while (temp.next != head)
	{
		System.out.print( temp.data + " ");
		temp = temp.next;
	}
		System.out.print( temp.data + " ");

	Node last = head.prev;
	temp = last;

	System.out.print( "\nBackward direction: ");
	while (temp.prev != last)
	{
		System.out.print( temp.data + " ");
		temp = temp.prev;
	}
		System.out.print( temp.data + " ");
}

// Driver code
public static void main(String args[])
{
	Node head = null;

	head =insertEnd(head, getNode(1));
	head =insertEnd(head, getNode(2));
	head =insertEnd(head, getNode(3));
	head =insertEnd(head, getNode(4));
	head =insertEnd(head, getNode(5));

	System.out.print( "Current list:\n");
	display(head);

	head = reverse(head);

	System.out.print( "\n\nReversed list:\n");
	display(head);
}
}
