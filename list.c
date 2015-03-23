#include <stdio.h>
#include <stdlib.h>




typedef struct node{				//Defining a Node.
	int data; 
	struct node* next; 
	}node;					//Creating a Node, a list's head , and an iterator. 

node* list=NULL;				//Creating a list's head and an iterator.



void add(int value){	//Node adding function.
	
				//Creating pointers to 
	node* new;		// create a new node
	node* iterator= NULL;	// let the free pointer points  
	iterator = list;	// to the list's head.

	if(list=NULL){				//If the List is empty,
	new = (node*)malloc(sizeof(node));	//create the first node
	new->data = value;			//and let list point to it.
	new->next = NULL;
	list = new;
	}

	else{
	 while(iterator->next != NULL){	//Until we found the free spot iterate
		iterator = iterator->next;	// through the list.
	 }
	 new = (node*)malloc(sizeof(node));	//Now create a new Node.
	 new->data = value;
	 new->next = NULL;
	} 
}



void prettyPrint(){
 
 if(list != NULL)	//if the list is non-empty
	{
	printf("Content of list is the following : ");
	node* read = NULL ;
	read = list; 
	while (read->next !=NULL){
	 printf("%d", read->data);	//Print each node's value 
	 read = read->next; 		// until the one before the last
	}
	printf("%d", read->data);	//Print the last node value
	}
else 					//If the list is empty just say it.
	{
	printf("Your list is empty.");
	}
 } 

node* find(int);

int delete(int value){
 
 node* found = NULL;
 found = find(value);	
 if(found != NULL)				//If the find() function found
	{					// a pointer do :
  	node* beforedelete = found;
  	node* todelete = beforedelete->next; 
  	beforedelete->next = todelete->next;	//make the node before the one 
  						//to delete pointing to the node
						// after the one to delete

	free(todelete);				//Free the space used for the
 	return 1; 				// deleted node.
 	}
 	else return 0 ; 
 } 



node* find(int avalue){
 	node* pointer = NULL;
	pointer = list;
 	while(pointer->next !=NULL)
	{
  	node* anext = NULL;
	anext = pointer->next; 
  	if(anext->data == avalue) return pointer;  
  	pointer = pointer->next; 
 	}
 	return NULL; 
}
