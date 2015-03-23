#include <stdio.h>
#include <stdlib.h>
#include "list.h"



 
node* list=NULL;				//Creating a list's head .



void add(int value){				//Node adding function.
 	
	printf("hey");		 
	node* new;		
					
	if(list=NULL){				//if empty list create the first node
	printf("coucou"); 
	new = (node*)malloc(sizeof(node)); 
	new->data = value; 
	new->next = NULL;
	list = new; 
	}

	else if(list != NULL) {			//Else iterate through list 
	 
	node* iterator = list; 
	
/*	while(iterator->next  != NULL)
	 {					// until we found the free spot 
		iterator = iterator->next;	
	 }
	 new = (node*)malloc(sizeof(node));
	 new->data = value;
	 new ->next = NULL;   
	 iterator->next = new; 
*/	} 
}



void prettyPrint(){
 
 if(list != NULL)	//if the list is non-empty
 {
	printf("Content of list is the following : \n");
	node* read =  list; 
	while (read !=NULL){
	 printf("%d", read->data);	//Print each node's value 
	 read = read->next; 		// until the one before the last
	}
 }
 else if (list == NULL)			//If the list is empty just say it.
 {
 printf("Your list is empty.\n"); 
 }
} 


node* find(int);


boolean delete(int value){
 
 node* found;
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
 	node* pointer =list;
	node* anext;
	
 	while(pointer !=NULL)
	{
	anext = pointer->next; 
     	 if(anext->data == avalue) return pointer;  
  	pointer = anext; 
 	}
 	return NULL; 
}
