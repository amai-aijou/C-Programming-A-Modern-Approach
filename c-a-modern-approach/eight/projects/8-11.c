/******************************************
 * Name: 8-11.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Tue Sep  2 09:24:42 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

#define NUM 15

int main(void) {

	int num;
	int ch;
	int i = 0;
	int count;

	char phone[NUM] = {0};
	
	// Instead of variable, it stores the data live
	printf("Enter phone number (alphanumeric): ");

	while ((ch = getchar()) != '\n') {

		if (ch >= 65 || ch <= 90) {
			switch (toupper(ch)) {
				case 65: case 66: case 67:
					phone[count] = '2';	
					break;
				case 68: case 69: case 70:	
					phone[count] = '3';
					break;
				case 71: case 72: case 73:
					phone[count] = '4';
					break;
				case 74: case 75: case 76:	
					phone[count] = '5';
					break;
				case 77: case 78: case 79:
					phone[count] = '6';
					break;
				case 80: case 81: case 82: case 83:
					phone[count] = '7';
					break;
				case 84: case 85: case 86:	
					phone[count] = '8';
					break;
				case 87: case 88: case 89: case 90:
					phone[count] = '9';
					break;
				default:
					phone[count] = ch;	
			}

		} 
		
		count++;
	}

	printf("In numeric form: ");

	for (i = 0; i < count; i++) {
		printf("%c", phone[i]);
	}
	
	// Print newline so terminal returns cursor on blank line
	printf("\n");

	return 0;
}
