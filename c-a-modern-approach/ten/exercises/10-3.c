/******************************************
 * Name: 10-3.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Feb  1 12:48:57 PM CST 2026
 ******************************************/

#include <stdio.h>

int i1;

int main(void) {

	int i2;

	if (true) {
		int i3;
	}

}


/*****ANSWER*****
 *
 * The function could contain, theoretically, limitless copies of i, with nested loop blocks;
 * however, I think a more reasonable answer is three: Global, Function, Block scope
