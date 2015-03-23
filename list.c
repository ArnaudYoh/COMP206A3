#include <stdio.h>
#include <stdlib.h>
#include "list.h"


node* list=NULL;				//Creating a list's head .
 

void add(int value){				//Node adding function.
 	
			 
	node* new;		
					
	if(list==NULL){				//if empty list create the first node 
	new = (node*)malloc(sizeof(node)); 
	new->data = value; 
	new->next = NULL;
	list = new; 
	}

	else if(list != NULL) {			//Else iterate through list 
	 
	node* iterator = list; 
	
	while(iterator->next  != NULL)
	 {					// until we found the free spot 
		iterator = iterator->next;	
	 }
	 new = (node*)malloc(sizeof(node));
	 new->data = value;
	 new ->next = NULL;   
	 iterator->next = new; 
	} 
}



void prettyPrint(){
 
 if(list != NULL)	//if the list is non-empty
 {
	printf("Content of list is the following : \n");
	node* read =  list; 
	while (read !=NULL){
	 printf("%d ", read->data);	//Print each node's value 
	 read = read->next; 		// until the one before the last
	}
 }
 else if (list == NULL)			//If the list is empty just say it.
 {
 printf("Your list is empty.\n"); 
 }
} 


node* find(int);


boolean delete(int avalue){
 
 node* found;
 found = find(avalue);	
 
if(list->data== avalue)
 {
 node* todelete = list; 
 list = list->next; 
 free(todelete); 
 } 
 
 
 else if(found != NULL)				//If the find() function found
	{					// a pointer do :
  	node* beforedelete = found;
  	node* todelete = beforedelete->next; 
  	beforedelete->next = todelete->next;	//make the node before the one 
  						//to delete pointing to the node
						// after the one to delete

	free(todelete);				//Free the space used for the
 	return 1; 				// deleted node.
 	}
 	else  return 0 ; 
 } 



node* find(int avalue){				//function for finding a node given an integer . 
 	
	node* pointer =list;
	node* anext;
		
	while(pointer->next !=NULL)
	{ 
	anext = pointer->next; 			//return the node before the one that matches.
     	 if(anext->data == avalue){ 
		return pointer;}  
  	pointer = anext; 
 	}
 	return NULL; 
}
