/******************************************
 * Name: 13-14.c (originally 8-16.c)
 * Purpose: Anagram tester
 * Author: amai-aijou
 * Date: Wed Jan  7 09:03:09 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h> // necessary for tolower() and toalpha()
#include <stdbool.h>

// ALPHA is size of array dimension; SIZE is size of all array dimensions
#define ALPHA 26

// Prototypes
bool are_anagrams(const char *word1, const char *word2);

int main(void) {

	int array[ALPHA] = {0};
	char ch;
	int i;
	int sum = 0;

	const char word1[100] = "racecar";
	const char word2[100] = "carrec";

	if (are_anagrams(word1, word2)) {
		printf("The words are anagrams.\n");
	} else {
		printf("The words are not anagrams.\n");
	}

	return 0;
}

bool are_anagrams(const char *word1, const char *word2) {

	const char *p;
	int i, sum;
	int count[ALPHA] = {0};

	for (p = word1; *p != 0; p++) {
		if (isalpha(*p)) {
			count[tolower(*p - 97)]++;
		}
	}

	for (p = word2; *p != 0; p++) {
		if (isalpha(*p)) {
			count[tolower(*p - 97)]--;
		}
	}

	for (i = 0; i < ALPHA; i++) {
		sum += count[i];
	}

	if (sum == 0) {
		return true;
	}

	return false;
}
