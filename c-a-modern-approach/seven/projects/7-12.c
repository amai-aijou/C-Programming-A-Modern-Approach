/******************************************
 * Name: 7-12.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Sep 21 04:49:58 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	float total;
	float input;
	char ch;

	printf("Enter an expression: ");
	
	// Pull in input operand
	scanf("%f", &input);

	// Assign initial value to total based on first operand
	total = input;

	// Retrieve next operator and next operand, then update "total" variable
	while ((ch = getchar()) != '\n') { 

		// Pull in input operand
		scanf("%f", &input);

		// Perform math using both
		switch (ch) {
			case '+':
				total += input;
				break;
			case '-':
				total -= input;
				break;
			case '*':
				total *= input;
				break;
			case '/':
				total /= input;
				break;
		}

	// End loop when newline character encountered
	}

	// Print final total
	printf("Value of expression: %.2f\n", total);

	return 0;
}

	/*  Debugging statements	
	 *	
	 *	printf("Current value of ch: %c\n", ch);
	 *	printf("Current value of total: %f\n", total);
	 *	printf("Current value of input: %f\n", input);
	 */
