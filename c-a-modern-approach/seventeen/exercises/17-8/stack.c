/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name:  
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Feb  8 12:15:48 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/* Reverse Polish Notation (RPN) Calculator */

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Include statements
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

// Macro definitions
#define STACK_SIZE 100

// Global variables
char stack[STACK_SIZE];
int top;

// Node struct
struct node {
	char value;
	struct node *next;
};

// Create Linked List Framework
struct node *first = NULL;


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Push an item onto the stack
bool push(char n) {

	printf("push!\n");

	struct node *new_node = malloc(sizeof(struct node));

	if(new_node == NULL) {
		printf("ERROR: Failed to add to list. Memory may not be available...or you just didn't want it bad enough\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = first;

	first = new_node;
	
	printf("DEBUG - new_node->value: %d\n", new_node->value);
	printf("DEBUG - push() adding: %d\n", first->value);
	//Returns TRUE if memory allocation was successful
	return first != NULL; 
}

// Remove an item from the stack
char pop() {

	struct node *trash;
	char stackValue;

	printf("pop!\n");

	if (is_empty()) {
		stack_underflow();
	} else {
		trash = first;
		stackValue = first->value;
		first = first->next;
		free(trash);
	}

	printf("DEBUG - pop() stackValue: %d\n", stackValue);
	return stackValue;
}

// Check if stack is empty
bool is_empty() {

	return first == NULL;
}

// Prevents a pop() on an already-empty stack from causing unintended behavior
void stack_underflow() {
	printf("ERROR: Stack Underflow - Operation not permitted. Resetting to original position.\n");
	printf("Note: this may result in a memory leak. Please close this application and re-open if necessary.\n");
	first = NULL;
}

// Prevents a push() on an already-full stack from causing unintended behavior
void stack_overflow() {

	printf("ERROR: Stack Overflow - Operation not permitted.\n");
	//If stack is full and attempting to add another item, immediately close program
	exit(EXIT_FAILURE);
}

int print_stack(int n) {
	// Print Stack
	for (int i = 0; i < 10; i++) {
		printf("stack[%d]: %d\n", i, stack[i]);
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

double calc() {

	printf("Value of expression: %d\n\n", first->value);

	free(first);

	printf("--------\n");
	printf("Note: Press m for menu\n");
	printf("Enter an RPN expresssion: ");
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                       ❤︎︎࣪    N O T E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
