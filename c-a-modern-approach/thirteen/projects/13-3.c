/******************************************
 * Name: 13-3.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Dec 28 01:04:06 PM CST 2025
 ******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
	bool in_hand[NUM_SUITS] [NUM_RANKS] = {false};
	int num_cards, rank, suit;
	const char rank_code[][10] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
							  "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
	const char suit_code[][10] = {"clubs", "diamonds", "hearts", "spades"};

	srand((unsigned) time(NULL));

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);

	printf("\nYour hand:\n");
	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;
		rank = rand() % NUM_RANKS;
		if (!in_hand[suit] [rank]) {
				in_hand[suit] [rank] = true;
				num_cards--;
				printf("%s of %s\n", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n");

	return 0;
}

