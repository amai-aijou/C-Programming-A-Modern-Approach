/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 19-3.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Jul  6 11:35:01 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

struct node {
	Item data;
	struct node *next;
};

// Define head and tail of linked list queue
static struct node *top = NULL, *tail = NULL;;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// Inserts an item at the end of the queue
void Insert(Item x) {

	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error on insert: queue is full\n");
		exit(EXIT_FAILURE);
	}

	if (tail == NULL) {
		top = new_node;
		new_node->data = x;
		new_node->next = NULL;
		tail = new_node;
		return;
	}

	new_node->data = x;
	new_node->next = tail->next;
	tail->next = new_node;
	tail = new_node;

}

// Removes an item from the beginning of the queue
Item Remove(void) {

	if (is_empty()) {
		printf("Error: Stack is empty\n");
		exit(EXIT_FAILURE);
	}

	struct node *trash;
	Item num = top->data;

	trash = top;
	top = top->next;
	free(trash);

	if (top == NULL) {
		tail = NULL;
	}

	return num;
}

// Returns the first item in the queue (without changing anything)
Item return_first(void) {

	return top->data;
}

// Returns the last item in the queue (without changing anything)
Item return_last(void) {

	return tail->data;
}

// Checks whether the queue is empty
bool is_empty(void) {
	
	return top == NULL;
}
