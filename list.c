#include <stdio.h>
#include <stlib.h>




typedef struct NODE{	//Defining a Node.
	int data; 
	NODE* next; 
	}aNode;



aNode* list = NULL; 	//Creating the List's head.



void add(int value){	//Node adding function.
	
	aNode* free;	//Creating pointers to find a freespot
	aNode* new;	// and create a new node
	free = list;	// let the free pointer points  
			// to the begining of the List.
	
	while(free->next != NULL){	//Until we found the free spot iterate
		free = free->next;	// through the list.
	}
	
	new = (aNode *)malloc(sizeof(aNode));	//Now create a new Node.
	new->data = &value;
	new->next = NULL;
	list->next = new; 
}



void prettyPrint(){
 
 if(list != NULL)	//if the list is non-empty
	{
	printf("Content of list is the following : ");
	aNode* read = list ;
	while (read->next !=NULL){
	prinf("%d ", read->data);	//Print each node's value 
	read = read->next; 		// until the one before the last
	}
	printf("%d ", read->data);	//Print the last node value
	}
else 					//If the list is empty just say it.
	{
	printf("Your list is empty.");
	}
 } 



int delete(int avalue){

 if(find(avalue)!=NULL)				//If the find() function found
	{					// a pointer do :
  	aNode* beforedelete = find(avalue);
  	aNode* todelete = beforedelete->next; 
  	beforedelete->next = todelete->next;	//make the node before the one 
  						//to delete pointing to the node
						// after the one to delete

	free(todelete);				//Free the space used for the
 	return 1; 				// node.
 	}
 	else return 0 ; 
 } 



NODE* find(int avalue){
 	aNode* pointer = list;
 	while(pointer->next !=NULL)
	{
  	aNode* anext = pointer->next; 
  	if(next->value == &avalue) return pointer;  
  	pointer = pointer->next; 
 	}
 	return NULL; 
}
