/******************************************
 * Name: 7-4.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Tue Sep  2 09:24:42 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	int num;
	int ch;
	
	// Instead of variable, it stores the data live
	printf("Enter phone number (alphanumeric): ");

	while ((ch = getchar()) != '\n') {

		if (ch >= 65 || ch <= 90) {
			switch (ch) {
				case 65: case 66: case 67:
					printf("2");
					break;
				case 68: case 69: case 70:	
					printf("3");	
					break;
				case 71: case 72: case 73:
			 		printf("4");
					break;
				case 74: case 75: case 76:	
					printf("5");
					break;
				case 77: case 78: case 79:
					printf("6");
					break;
				case 80: case 81: case 82: case 83:
					printf("7");
					break;
				case 84: case 85: case 86:	
					printf("8");
					break;
				case 87: case 88: case 89: case 90:
					printf("9");
					break;
				default:
					printf("%c", ch);
			}
		} 
	}

	
	// Print newline so terminal returns cursor on blank line
	printf("\n");

	return 0;


