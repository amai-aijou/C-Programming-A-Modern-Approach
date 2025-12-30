/******************************************
 * Name: 8-11.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Dec 29 09:10:01 PM CST 2025
 ******************************************/

#include <stdio.h>

#define BOARD_SIZE 8

int main(void) {

	int i, j, k, l;
	char checker_board[BOARD_SIZE][BOARD_SIZE]; 

	//Work in progress! need to figure out a clean way to alternate them.
	//Right now this just puts a B at the front of each line. need a quick check to see if i is even/odd first
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			if ((i + j) % 2 == 0) {
				checker_board[i][j] = 'B';
			} else {
				checker_board[i][j] = 'R';
			}
		}
	}

	printf("The current value of the array:\n");

	for (k = 0; k < BOARD_SIZE; k++) {
		printf("\n");
		
		for (l = 0; l < BOARD_SIZE; l++) {
			printf(" %c ", checker_board[k][l]);
		}
	}
	
	printf("\n");

	return 0;
}

