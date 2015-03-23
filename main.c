#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void main(){
 
 char filename[100];
 char answer[100];
 FILE* file =NULL;   
 char ch; 
 char line[100]; 
 int value; 
 int boolean;
 
 
 while(file == NULL ){						//ask the user until he enters an existing file name/ file path.
	printf("Please enter a filename or its path :\n "); 
	scanf("%s", filename);
	file = fopen(filename, "rt"); 
	}


 while ( !feof(file) )						//Create a node for each number present in the file.
 {								
	fscanf(file, "%d", &value);
	add(value);
 }


 prettyPrint();								//Print the LinkedList
  

 printf("Please enter a number you want to delete :\n ");		//Ask for an integer to delete.
 scanf("%d", &value );
 boolean = delete(value);						//Delete the value if found.
 if(boolean == false ) {printf("NUMBER WAS NOT FOUND\n");}		//Print the sentence according to the returned boolean.
	else {printf("NUMBER WAS DELETED\n");}
 prettyPrint();
 
 while(1){
  printf("Do you want me to take care of another integer ? :\n ");
  scanf("%s", answer);
  if (strcmp(answer,"yes")==0 || strcmp(answer,"YES")==0 		//if the user say yes then reask for an integer to delete
		|| strcmp(answer,"Y")==0 || strcmp(answer,"y")==0 
			|| strcmp(answer,"Yes")==0 )
  {
	printf("Which integer do you want me to delete ? :\n ");
	scanf("%d", &value);
	boolean = delete(value);					//delete the integer if present in the linkedlist.
	if (boolean == false ) {printf("NUMBER WAS NOT FOUND\n");}
		else{printf("NUMBER WAS DELETED\n");}
	prettyPrint();
  }
  else {break;} 
 }
 fclose(file);
}
