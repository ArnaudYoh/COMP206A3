#include <stdio.h>
#include <stdlib.h>


void main(){

 char answer[100];
 FILE* file = NULL;   
 char ch; 
 char line[900];
 char *read; 
 int value = 0; 
 int boolean;
 
 
 while(file == NULL ){						//ask the user until he enters an existing file name/ file path.
	printf("Please enter a filename or its path : "); 
	scanf("%s", answer);
	file = fopen (answer, "rt"); 
	}

 while ( (read = fgets(line,sizeof(line), file )) != NULL )	//Create a node for each number present in the file.
 {								
	value = atoi(read);
	add(value);
 }

 prettyPrint();							//Print the LinkedList

 printf("Please enter a number you want to delete : ");		//Ask for an integer to delete.
 scanf("%d", &value );
 boolean = delete(value);					//Delete the value if found.
 if(boolean ==0) {printf("NUMBER WAS NOT FOUND");}		//Print the sentence according to the returned boolean.
	else {printf("NUMBER WAS DELETED");}
 prettyPrint();
 
 while(1){
  printf("Do you want me to take care of another integer ? : ");
  scanf("%s", answer);
  if (strcmp(answer,"yes")==0 || strcmp(answer,"YES")==0 || strcmp(answer,"Y")==0 || strcmp(answer,"y")==0 || strcmp(answer,"Yes")==0 )
  {
	printf("Which integer do you want me to delete ? : ");
	scanf("%d", &value);
	delete(value);
	prettyPrint();
  }
  else {break;} 
 }
}
