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

#define STACK_SIZE 100

struct stack_type {
	Item contents[STACK_SIZE];
	int top;
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
	s->top = 0;
	return s;
}

void destroy(Stack s) {
	free(s);
}

void make_empty(Stack s) {
	s->top = 0;
}

bool is_empty(Stack s) {
	return s->top == 0;
}

bool is_full(Stack s) {
	return s->top == STACK_SIZE;
}

void push(Stack s, Item i) {
	if (is_full(s)) {
		terminate("Error in push: stack is full.");
	}
	s->contents[s->top++] = i;
}

Item pop(Stack s) {

	if (is_empty(s)) {
		terminate("Error in push: stack is empty.");
	}

	return	s->contents[--s->top];
}
