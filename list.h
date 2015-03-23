typedef struct node{
	int data; 
	struct node* next; 
}node;

#ifndef boolean
	typedef int boolean; 
	#define true 1
	#define false 0
#endif
 
void add(int);

boolean delete(int);

void prettyPrint();


