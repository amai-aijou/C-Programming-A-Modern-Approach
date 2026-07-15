/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name:  
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Feb  8 12:15:48 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Include statements
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "19-2.h"

// Macro definitions
#define STACK_SIZE 100

struct stack_type {
	char stack[STACK_SIZE];
	int top;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
Stack create(void) {

	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL) {
		printf("Error in crease: stack could not be created.");
		exit(EXIT_FAILURE);
	}
	s->top = 0;

	return s;
}

// Push an item onto the stack
char push(Stack s, char n) {

	// DEBUG ONLY
	// printf("push!\n");

	// Confirm stack isn't full, add current contents to stack, then increment top to next stack position
	if (is_full(s)) {
		stack_overflow();
	} else {
		return s->stack[s->top++] = n;
	}
}

// Remove an item from the stack
char pop(Stack s) {

	// DEBUG ONLY
	// printf("pop!\n");

	// Confirm stack isn't empty, then reduce the stack position by one.
	// NOTE: contents of array are not erased until overwritten
	if (is_empty(s)) {
		stack_underflow();
	} else {
		return s->stack[--s->top];
	}
}

void evaluate(Stack s) {

    printf("Value of expression: %d\n\n", s->stack[s->top - 1]);
    printf("--------\n");
    printf("Note: Press m for menu\n");
    printf("Enter an RPN expresssion: ");
}

// Check if stack is empty
bool is_empty(Stack s) {
	// returns "true" if stack is empty
	return s->top == 0;
}

// Check if stack is full
bool is_full(Stack s) {
	//returns "true" if stack is full
	return s->top == STACK_SIZE;

}

// Prevents a pop() on an already-empty stack from causing unintended behavior
void stack_underflow(Stack s) {
	printf("ERROR: Stack Underflow - Operation not permitted.\n");
	printf("Resetting to original position.\n\n");
	s->top = 0;
}

// Prevents a push() on an already-full stack from causing unintended behavior
void stack_overflow() {

	printf("ERROR: Stack Overflow - Operation not permitted.\n");
	//If stack is full and attempting to add another item, immediately close program
	exit(EXIT_FAILURE);
}

int print_stack(Stack s, int n) {

	int i;

	// Print Stack
	for (int i = 0; i < 10; i++) {
		printf("stack[%d]: %d\n", i, s->stack[i]);
	}
}

void help() {
	printf("############### CALCULATOR ###############\n\n");
	printf("This calculator uses Reverse Polish Notation.\n"
			"Operators are placed *after* their operands."
			"Operators are also read in reverse order.\n"

			"Example: 1+2-3*5= becomes 1 2 3 5 * - + =\n");
			
	printf("Note: press h to repeat this message\n");
	printf("##########################################\n\n");

	printf("Enter an RPN expresssion: ");
}
void menu() {
	printf("OPTIONS\n");
	printf("h\thelp\n");
	printf("m\tmenu\n");
	printf("q\tquit\n\n");

	printf("Enter an RPN expresssion: ");
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                       ❤︎︎࣪    N O T E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// print_stack() exists primarily for debugging purposes
