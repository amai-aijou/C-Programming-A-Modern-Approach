/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
    ❤︎︎࣪ Name: 12-4.c (from 10-1.c)											 
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

#define STACK_SIZE 100

char contents[STACK_SIZE];
char *top_ptr = &contents[0];
bool underflow = false;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void make_empty(void); 
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_underflow(void);
void stack_overflow(void);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

char main(void) {
	
	char ch;
	int maxStack = 0;
	int i;

	printf("Enter parentheses and/or braces: ");

	while ((ch = getchar()) != '\n') {

		if (ch == '{' || ch == '(') {
			push(ch);	
		}

		if (ch == '}' || ch == ')') {
			pop();	
		}

		maxStack++;
	}

	// Print current contents of model
	printf("Current contents: ");
	for (i = 0; i < maxStack; i++) {
		printf("%c \n", contents[i]);
	}
	printf("\n");


	if (is_empty() && (underflow == false)) {
		printf("Parentheses/braces are nested properly.\n");
		//printf("Empty!\n");
	} else stack_underflow();

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void make_empty(void) {
	// 12-4: Set the memory address of top_ptr to first array address (contents[0])
	top_ptr = &contents[0];
}

bool is_empty(void) {
	// 12-4: Check if memory address of top_ptr matches first array address
	return (top_ptr == &contents[0]);
}

bool is_full(void) {
	// 12-4: Check if memory address of top_ptr matches max array address
	return (top_ptr >= &contents[STACK_SIZE]);
}

void push(char i) {
	if (is_full())
		stack_overflow();
	else
		// 12-4: set *top_ptr to i, then increment top_ptr to next memory address
		*top_ptr++ = i;
}

char pop(void) {
	if (is_empty())
		stack_underflow();
	else
		// 12-4: decrements top_ptr memory address, then returns the value at that (now lowered) address
		return *--top_ptr;
}

void stack_underflow(void) {
	printf("Stack Underflow.\n");
	underflow = true;
}

void stack_overflow(void) {
	exit(EXIT_FAILURE);
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    D E B U G G I N G    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// printf("Stack size: %d | Top of Stack: %c\n", top, contents[top - 1]);
