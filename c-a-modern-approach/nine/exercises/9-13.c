/******************************************
 * Name: 9-13.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Jan 19 08:23:30 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 8

int evaluate_position(char board[*][BOARD_SIZE]);

int main(void) {
	
	int score;
	char board[BOARD_SIZE] [BOARD_SIZE] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
		                                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                						   {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
							               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
							               {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
							               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
							               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
							               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

	//printf("This is a test. It should currently read 'r': %c\n", board[0][0]);

	score = evaluate_position(board);

	if (score > 0) {

		printf("Current Score: White is winning by %d\n", score);
	} else if (score == 0) {
		printf("Current Score: tie\n");
	} else if (score < 0) {
		printf("Current Score: Black is winning by %d\n", (score * -1));
	} else {
		printf("You should never see this text\n");
	}

	return 0;
}

int evaluate_position(char board[][BOARD_SIZE]) {

	int x, y;
	int score = 0;

	for (x = 0; x < BOARD_SIZE; x++) {
		for (y = 0; y < BOARD_SIZE; y++) {
			switch (board[x][y]) {
				case 'Q':
					score += 9;
					break;
				case 'R':
					score += 5;
					break;
				case 'B': case 'N':
					score += 3;
					break;
				case 'P':
					score += 1;
					break;
				case 'q':
					score -= 9;
					break;
				case 'r':
					score -= 5;
					break;
				case 'b': case 'n':
					score -= 3;
					break;
				case 'p':
					score -= 1;
					break;
				default:
					break;
			}
		}
	}

	return (score);
}
