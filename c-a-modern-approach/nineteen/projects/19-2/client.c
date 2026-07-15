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

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char ch;
	int num1 = 0, num2 = 0;
	Stack s1;

	s1 = create();

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
			case 'h': help(); 
					  break;
			case 'm': menu();
					  break;
			case 'q': exit(EXIT_SUCCESS);

			// Numerical Operands are added to the stack
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
					  // Push subtracts 48 to convert from ASCII char to int
					  push(s1,ch - 48);
					  break;

			// Operators are applied to operands in the stack in reverse order
			case '+': push(s1,(pop(s1) + pop(s1)));
					  break;
			case '-': num2 = pop(s1);
					  num1 = pop(s1); 
					  push(s1,(num1 - num2));
					  break;
			case '*': push(s1,(pop(s1) * pop(s1)));
					  break;
			case '/': num2 = pop(s1);
					  num1 = pop(s1);
					  push(s1,(num1 / num2));
			case '=': evaluate(s1);
		}

	}

	return 0;
}
