/******************************************
 * Name: 9-14.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Jan 19 09:01:38 PM CST 2026
 ******************************************/

#include <stdio.h>

bool has_zero(int a[], int n);

int main(void) {

}

bool has_zero(int a[], int n) {
	int i;

	for (i = 0; i < n; i++) {
		if (a[i] == 0)
			return true;
//		else
//			return false;
	}
	return false;
}

/*****SOLUTION*****
 *
 * "return true" works fine.
 * "else return false" would immediately return after one iteration of the loop.
 * need to place the return statement outside the loop to give it a chance to check every array value
 * only in the event of a 0-value will it terminate early
