/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 19-4b.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Jul  9 01:31:31 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	Item data;
	struct node *next;
};

struct stack_type {
	struct node *top;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/


static void terminate(const char *message) {

	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(void) {

	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL) {
		terminate("Error in create: stack could not be created.");
	}
	s->top = NULL;
	return s;
}

void destroy(Stack s) {

	make_empty(s);
	free(s);
}

void make_empty(Stack s) {

	while (!is_empty(s)) {
		pop(s);
	}
}

bool is_empty(Stack s) {
	return s->top == NULL;
}

bool is_full(Stack s) {
	return false;
}

void push(Stack s, Item i) {

	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		terminate("Error in push: stack is full.");
	}
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

Item pop(Stack s) {

	struct node *old_top;
	Item i;

	if (is_empty(s)) {
		terminate("Error in push: stack is empty.");
	}

	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);

	return i;
}

// Inserts an item at the end of the queue
void Insert(Item x) {

