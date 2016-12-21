/*
Doubly-linked Node is the node that contains 
two addresses, one in front and one in back. 



*/


/*/////////////////////////////////
Single Node: 

struct Node{
	int val;
	Node *next;
}


double linked Node: 

struct Node{
	int val;
	Node *next=NULL;
	Node *prev=NULL;   //extra address 
}


//////////////////////////////*/








//This is the first thing you need to do when you are 
//adding new node infront of the existed node.
//because you don't want to lose the address of 
//original Node. 
Node* tmp = head; 
head = new Node(12); // creating new head Node. 
head -> next = tmp;
head -> prev = NULL; 

//This is MUST to add extra.. 