/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
    ❤︎︎࣪ Name: 10-1.c 												 
    ❤︎︎࣪ Purpose: 													 
    ❤︎︎࣪ Author: amai-aijou                           				 
    ❤︎︎࣪ Date: Sun Feb  1 12:58:00 PM CST 2026                      
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "19-1.h"

#define STACK_SIZE 100

struct stack_type {
	char contents[STACK_SIZE];
	int top;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
Stack create(void) {

	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL) {
		printf("Error in create: stack could not be created.");	
		exit(EXIT_FAILURE);
	}
	s->top = 0;

	return s;
}

bool is_empty(Stack s) {
	return s->top == 0;
}

bool is_full(Stack s) {
	return s->top == STACK_SIZE;
}

void push(Stack s, char i) {
	if (is_full(s))
		stack_overflow();
	else
		s->contents[s->top++] = i;
}

char pop(Stack s) {
	if (is_empty(s))
		stack_underflow();
	else
		return s->contents[--s->top];
}

void stack_underflow(void) {
	printf("Stack Underflow. Parentheses not nested correctly!\n");
	exit(EXIT_FAILURE);
}

void stack_overflow(void) {
	exit(EXIT_FAILURE);
}

void print_leftovers(Stack s, int maxStack) {

	int i;

	// Print current contents of model
	printf("Current contents: ");
	for (i = 0; i < maxStack; i++) {
		printf("%c \n", s->contents[i]);
	}
	printf("\n");
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    D E B U G G I N G    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// printf("Stack size: %d | Top of Stack: %c\n", top, contents[top - 1]);
