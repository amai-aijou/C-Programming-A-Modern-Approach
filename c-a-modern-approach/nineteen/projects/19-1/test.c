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

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;
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
	top = 0;
}

bool is_empty(void) {
	return top == 0;
}

bool is_full(void) {
	return top == STACK_SIZE;
}

void push(char i) {
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

char pop(void) {
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
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
