/******************************************
 * Name: 8-10.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Dec 29 09:03:42 PM CST 2025
 ******************************************/

#include <stdio.h>

#define BOARD_SIZE 8

int main(void) {
	
	char array[BOARD_SIZE] [BOARD_SIZE] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
		                                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                						   {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
							               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
							               {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
							               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
							               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
							               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

	printf("This is a test: %d", array[0][0]);
	printf("\n");

	return 0;
}
