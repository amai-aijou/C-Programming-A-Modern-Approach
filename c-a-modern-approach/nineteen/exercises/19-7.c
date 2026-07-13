/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 19-7.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Jul  4 04:42:37 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
	Item *contents;
	int top;
	int size;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void expand(Stack s) {

	Item *tempContents = s->contents;

	tempContents = realloc(s->contents, ((s->size * sizeof(Item)) * 2));

	if (tempContents == NULL) {
		terminate("Error in expand: stack could not be expanded.");
	} else {
		printf("Expansion successful. Memory allocated.\n");
		s->contents = tempContents;
}

static void terminate(const char *message) {

	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(int size) {

	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL) {
		terminate("Error in create: stack could not be created.");
	}

	s->contents = malloc(size * sizeof(Item));;

	if (s->contents == NULL) {
		free(s);
		terminate("Error in create: stack could not be created.");
	}

	s->top = 0;
	s->size = size;

	return s;
}

void destroy(Stack s) {
	free(s->contents);
	free(s);
}

void make_empty(Stack s) {
	s->top = 0;
}

bool is_empty(Stack s) {
	return s->top == 0;
}

bool is_full(Stack s) {
	return s->top == s->size;
}

void push(Stack s, Item i) {
	if (is_full(s)) {
		printf("Stack is full. Attempting to expand.!");
		expand(s);
	}
	s->contents[s->top++] = i;
}

Item pop(Stack s) {

	if (is_empty(s)) {
		terminate("Error in pop: stack is empty.");
	}

	return	s->contents[--s->top];
}
