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

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char ch;

	// Call help() to serve as an intro and instruction set, then ask for expression
	help();
	printf("Enter an RPN expresssion: ");

	while ((ch = getchar()) != '\n') {
		
		// Check for special options
		switch (tolower(ch)) {
			// Special menu selections
			case 'h': help(); 
					  break;
			case 'm': menu();
					  continue;
			case 'q': exit(EXIT_SUCCESS);
			// Numerical Operands are added to the stack
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
					  push(ch);
			// Operators are applied to operands in the stack in reverse order
			case '+': 
					  push(pop() + pop());
			case '-':
			case '*':
			case '/':
		}

		// example
		// 5 8 * 4 9 - / =
		// 
		// push(5);
		// push(8);
		// pop() * pop();
		// push(4)
		// push(9)
		// pop() pop() 

	}

	// Print the stack
	print_stack(10);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Push an item onto the stack
char push(char n) {

	if (is_full()) {
		stack_overflow();
	} else {
		return stack[top++] = n;
	}
}

// Remove an item from the stack
char pop() {

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
}

// Prevents a push() on an already-full stack from causing unintended behavior
void stack_overflow() {
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
	printf("This calculator uses Reverse Polish Notation. Operators are placed"
			"*after* their operands (and in reverse order!)\n Example: 1+2-3*5= becomes 1 2 3 5 * - + =");
			
	printf("Note: press h to repeat this message\n");
	printf("##########################################\n\n");
}
void menu() {
	printf("OPTIONS\n");
	printf("h\thelp\n");
	printf("m\tmenu\n");
	printf("q\tquit\n\n");
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                       ❤︎︎࣪    N O T E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/* Stack
 *
 * 1 2 3 * + =
 *
 * push(1);
 * push(2);
 * push(3);
 *
 *
 * 
 */
