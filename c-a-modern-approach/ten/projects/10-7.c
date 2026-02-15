/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name:  
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Feb 13 10:27:55 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_DIGITS 10

// Global Variables
char digits[4][MAX_DIGITS * 4];
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},  //0
                             {0, 1, 1, 0, 0, 0, 0},  //1
                             {1, 1, 0, 1, 1, 0, 1},  //2
                             {1, 1, 1, 1, 0, 0, 1},  //3
                             {0, 1, 1, 0, 0, 1, 1},  //4
                             {1, 0, 1, 1, 0, 1, 1},  //5
                             {1, 0, 1, 1, 1, 1, 1},  //6
                             {1, 1, 1, 0, 0, 0, 0},  //7
                             {1, 1, 1, 1, 1, 1, 1},  //8
                             {1, 1, 1, 1, 0, 1, 1}}; //9

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char ch;
	int digit = 0;
	int position = 0;

	// Clear array (just in case!), then make initial request
	clear_digits_array();
	printf("Enter a number: ");

	// Read input until end of line
	while ((ch = getchar()) != '\n') {

		// Ensure number does not exceed current MAX_DIGITS; otherwise, exit
		if (position >= MAX_DIGITS) {
			printf("Stack Overflow!!");
			exit(EXIT_FAILURE);	
		}

		// If char is a digit, process_digit() and increment position
		if (isdigit(ch)) {

			process_digit((ch - '0'), position);
			position++;
		}
	}

	// Print out the array, then exit
	print_digits_array();

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Zeroes out the array
void clear_digits_array(void) {

	int i,j;

	for (i = 0; i < MAX_DIGITS; i++) {
		for (j = 0; j < (MAX_DIGITS * 4); j++) {
			digits[i][j] = ' ';
		}
	}
}

// Store the seven-segment representation of digit into a specified position in digits[] array
void process_digit(int digit, int position) {

	int i;
 
	// For each segment position, check if it's set to true for a given digit; then, add its character to the array
	for (i = 0; i < 7; i++) { 

		// Check if that segment is a 1 or 0
		if (segments[digit][i]) {

			// Add ascii char to the array if true
	 		switch (i) {
				case 0:
					digits[0][1 + (position * 4)] = '_';
					break;
				case 1:
					digits[1][2 + (position * 4)] = '|';
					break;
				case 2:
					digits[2][2 + (position * 4)] = '|';
					break;
				case 3:
					digits[2][1 + (position * 4)] = '_';
					break;
				case 4:
					digits[2][0 + (position * 4)] = '|';
					break;
				case 5:
					digits[1][0 + (position * 4)] = '|';
					break;
				case 6:
					digits[1][1 + (position * 4)] = '_';
					break;
			}
		}
	}
}

// Prints out the array
void print_digits_array(void) {

	int i, j;

	// Outer loop for row, inner loop for column
	for (i = 0; i < 4; i++) {
		for (j = 0; j < (MAX_DIGITS * 4); j++) {
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                       ❤︎︎࣪    N O T E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*	 
 * Zero is on top, Six is in the middle (seven locations total)
 *  _      _  _       _      _   _   _
 * | |  |  _| _| |_| |_  |_   | |_| |_|
 * |_|  | |_  _|   |  _| |_|  | |_|   |
 *
 *  0123
 * 0-_--
 * 1|_|-
 * 2|_|-
 * 3----
 *                   position:   0  1  2  3  4  5  6
 *                              ---------------------
 * const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
 *                     column:   1, 2, 2, 1, 0, 0, 1
 *                        row:   0, 1, 2, 2, 2, 1, 1
 *
 *    correspondes with lines:   1, 2, 3, 3, 3, 2, 2
 *
 *

 digit[0][1 + (digNum * 4)] //0 '_'
 digit[1][2 + (digNum * 4)] //1 '|'
 digit[2][2 + (digNum * 4)] //2 '|'
 digit[2][1 + (digNum * 4)] //3 '_'
 digit[2][0 + (digNum * 4)] //4 '|'
 digit[1][0 + (digNum * 4)] //5 '|'
 digit[1][1 + (digNum * 4)] //6 '_'

// DEBUGGING STATEMENTS
printf("DEBUG TIME (sigh)....\n");
printf("isdigit: %d\n", isdigit(ch));
printf("digits[0][0]: %d\n", digits[0][0]);
printf("values of ch(c):%c ch(d):%d\n", ch, ch);
*/
