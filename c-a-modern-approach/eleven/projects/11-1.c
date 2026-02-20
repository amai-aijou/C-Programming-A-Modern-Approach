
/******************************************
 * Name: 11-1.c
 * Purpose: 
 * Author: jolson
 * Date: Fri Apr 18 06:01:15 PM CDT 2025
 ******************************************/

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
	int dollars;
	printf("Please enter a dollar amount: $");
	scanf("%d", &dollars);

	int twenties;
	int tens;
	int fives;
	int ones;

	pay_amount(dollars, &twenties, &tens, &fives, &ones);

	printf("$20 bills: %d\n", twenties);
	printf("$10 bills: %d\n", tens);
	printf("$5 bills: %d\n", fives);
	printf("$1 bills: %d\n", ones);

}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
		
	*twenties 	= (dollars / 20);
	*tens		= (dollars - (*twenties * 20)) / 10;
	*fives 		= (dollars - (*twenties * 20 + *tens * 10)) / 5;
	*ones		= (dollars - (*twenties * 20 + *tens * 10 + *fives * 5)) / 1;
}


