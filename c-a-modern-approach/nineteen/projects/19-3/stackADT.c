/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: stackADT.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Jul  4 04:42:37 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
	Item data;
	struct node *next;
};

struct stack_type {
	struct node *top;
	int len;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
//19-4: Add length() to return the value of stack_type->len
int length(Stack s) {

	return s->len;
}

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
	s->len = 0;
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

	s->len++;
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

	s->len--;
	return i;
}
