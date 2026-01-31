/******************************************
 * Name: 9-8.c
 * Purpose: Craps Game
 * Author: amai-aijou
 * Date: Mon Jan 26 04:00:18 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int roll_dice(void);
bool play_game(void);

int main(void) {

	char gameCont;
	bool result;
	int win = 0;
	int lose = 0;

	// Generate seed value for rand() based on current time().
	// NOTE: Must be at start of main() to prevent running multiple times, as this value only changes when time() second increments.
	srand((unsigned) time(NULL));

	printf("Let's play Craps!");


	// Core gameplay loop. Plays a game of Craps, records the result, and asks user to play again.
	do {
		result = play_game();
		
		if (result == true) {
			win++;
		} else {
			lose++;
		}
		
		printf("Play again? ('y' to continue): ");
		scanf(" %c", &gameCont);
		
	} while (tolower(gameCont) == 'y');

	// Display total number of wins and losses, then exit
	printf("gameCont: %c", tolower(gameCont));
	printf("Wins: %d\tLosses: %d\n", win, lose);
	return 0;
}

// Generates two random numbers (1-6) and returns their sum.
int roll_dice(void) {

	int dice1 = (rand() % 6) + 1;
	int dice2 = (rand() % 6) + 1;

	return (dice1 + dice2);
}

// Play one game of Craps. Returns true for a win, false if you're a big fat loser! Also displays outputs for dice rolls
// Roll one: Win if 7 or 11, Lose if 2, 3, or 12. Roll two+: Win if same as previous roll, Lose if 7.
bool play_game(void) {

	int roll;
	int point = 1;
	bool outcome = true;


	roll = roll_dice();
	printf("You rolled: %d\n", roll);

	switch (roll) {
		case 7: case 11:
			printf("You win - LUCKY!!!\n");
			return true;
		case 2: 
			printf("You Lose - Snake Eyes!!!\n");
			return false;
		case 3:
			printf("You Lose!\n");
			return false;
	}

	while (roll != 7) {

		// Roll Dice
		roll = roll_dice();
		printf("You rolled: %d\n", roll);

		if (roll == point) {
			printf("You Win!\n");
			return true;
		}
	
		// Set Point
		point = roll;
		printf("Your point is %d\n", point);
	}

	printf("You lose!\n");

	return false;
}
