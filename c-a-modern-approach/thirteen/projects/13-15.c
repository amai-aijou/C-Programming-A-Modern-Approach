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

// Macro definitions
#define STACK_SIZE 100

// Global variables
char stack[STACK_SIZE];
int top;

// Prototypes


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char push(char n);
char pop();
bool is_empty();
bool is_full();
void stack_underflow();
void stack_overflow();
int print_stack(int n);
void help();
void menu();
int evaluate_RPN_expression(const char *expression);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char ch;
	int num1 = 0, num2 = 0;

	// Edit this to adjust the expression solved by pressing e
	const char expression[100] = "1 2 3 5 * - + =";

	// Call help() to serve as an intro and instruction set, then ask for expression
	help();

	// Core input and calculation loop
	while ((ch = getchar()) != 'q') {

		// Variables used to hold pop() results temporarily; reset with each loop
		num1 = 0;
		num2 = 0;
		
		// Switch statement checks for special options, such as help() or menu(), then performs calculation
		switch (tolower(ch)) {
			
			// Special menu selections
			case 'e': evaluate_RPN_expression(expression);
			case 'h': help(); 
					  break;
			case 'm': menu();
					  break;
			case 'q': exit(EXIT_SUCCESS);

			// Numerical Operands are added to the stack
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
					  // Push subtracts 48 to convert from ASCII char to int
					  push(ch - 48);
					  break;

			// Operators are applied to operands in the stack in reverse order
			case '+': push(pop() + pop());
					  break;
			case '-': num2 = pop();
					  num1 = pop(); 
					  push(num1 - num2);
					  break;
			case '*': push(pop() * pop());
					  break;
			case '/': num2 = pop();
					  num1 = pop();
					  push(num1 / num2);
			case '=':
					  printf("Value of expression: %d\n\n", stack[top - 1]);
					  printf("--------\n");
					  printf("Note: Press m for menu\n");
					  printf("Enter an RPN expresssion: ");
		}

	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Push an item onto the stack
char push(char n) {

	// DEBUG ONLY
	// printf("push!\n");

	// Confirm stack isn't full, add current contents to stack, then increment top to next stack position
	if (is_full()) {
		stack_overflow();
	} else {
		return stack[top++] = n;
	}
}

// Remove an item from the stack
char pop() {

	// DEBUG ONLY
	// printf("pop!\n");

	// Confirm stack isn't empty, then reduce the stack position by one.
	// NOTE: contents of array are not erased until overwritten
	if (is_empty()) {
		stack_underflow();
	} else {
		return stack[--top];
	}
}

// Check if stack is empty
bool is_empty() {
	// returns "true" if stack is empty
	return top == 0;
}

// Check if stack is full
bool is_full() {
	//returns "true" if stack is full
	return top == STACK_SIZE;

}

// Prevents a pop() on an already-empty stack from causing unintended behavior
void stack_underflow() {
	printf("ERROR: Stack Underflow - Operation not permitted.\n");
	printf("Resetting to original position.\n\n");
	top = 0;
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

// Chapter 13 - Project 15
int evaluate_RPN_expression(const char *expression) {
	
	const char *p;
	int num1, num2;

	for (p = expression; *p != '\0'; p++) {

		num1 = 0;
		num2 = 0;

		switch (tolower(*p)) {
			
			// Numerical Operands are added to the stack
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
					  // Push subtracts 48 to convert from ASCII char to int
					  push(*p - 48);
					  break;

			// Operators are applied to operands in the stack in reverse order
			case '+': push(pop() + pop());
					  break;
			case '-': num2 = pop();
					  num1 = pop(); 
					  push(num1 - num2);
					  break;
			case '*': push(pop() * pop());
					  break;
			case '/': num2 = pop();
					  num1 = pop();
					  push(num1 / num2);
			case '=':
					  printf("Value of expression: %d\n\n", stack[top - 1]);
					  printf("--------\n");
					  printf("Note: Press m for menu\n");
					  printf("Enter an RPN expresssion: ");
			case ' ': break;
		}
	}
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                       ❤︎︎࣪    N O T E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// print_stack() exists primarily for debugging purposes
