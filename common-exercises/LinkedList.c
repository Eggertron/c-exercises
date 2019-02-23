/*	Linked List
	Author: Edgar Han
	Date: 6/15/2016
	
	This is a simple design of a linked list. I chose this design
	instead of the ductape method.
*/

#include <stdio.h>
#include <stdlib.h>

struct _node {
	int x;
	struct _node * next;
};

typedef struct _node node;

struct _node * NewNode(int x)
{
	struct _node * temp = malloc( sizeof( struct _node ) );
	temp->x = x;
	temp->next = NULL;
	return temp;
}

struct _node * getLastNode(struct _node * root)
{
	struct _node * traversing = root;
	
	while ( traversing->next != NULL )
		traversing = traversing->next;
	
	return traversing;
}

int AddNode( struct _node * root, struct _node * node )
{
	struct _node * traversing = getLastNode(root);

	traversing->next = node;
	return 0;
}

int FreeAllNodes(struct _node * root)
{
	struct _node * killnode = root;
	while ( root->next != NULL )
	{
		root = root->next;
		free(killnode);				// figure out why this is giving problem
		killnode = root;			// found out, can't free something not malloc, like root
	}
	free(root);
	return 0;
}

int PrintList(struct _node * root)
{
	int i = 0;
	while ( root != NULL )
	{
		if ( i > 0 )
			printf(", ");
		printf("[%d] %d", i, root->x);
		root = root->next;
		i++;
	}
	printf("\n");
	return 0;
}

int debug()
{
	struct _node * root;
	//root.x = 20;
	root = NewNode(20);
	AddNode( root, NewNode( 75 ) );
	PrintList( root );
	AddNode( root, NewNode( 34 ) );
	PrintList( root );
	AddNode( root, NewNode( 66 ) );
	PrintList( root );

	FreeAllNodes( root );
	PrintList( root );
	return 0;
}

int main() {
	debug();
}