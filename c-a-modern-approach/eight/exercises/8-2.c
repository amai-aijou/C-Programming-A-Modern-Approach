/******************************************
 * Name: 8-2.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Dec 28 05:17:57 PM CST 2025
 ******************************************/

#include <stdio.h>

int main(void) {
	int letter_count[26];

	char ch = '1';

	letter_count[ch-'1'] = 7;

	printf("%d", letter_count[0]);

	return 0;
}

