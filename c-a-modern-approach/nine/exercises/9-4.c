/******************************************
 * Name: 9-4.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Fri Jan 16 06:41:18 PM CST 2026
 ******************************************/

#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void) {
	int month, day, year;

	printf("Enter the month, day, year: ");
	scanf("%d %d %d", &month, &day, &year);

	printf("Day of year: %d\n", day_of_year(month, day, year));

	return 0;
}

int day_of_year(int month, int day, int year) {

	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dayOfYear = 0;
	int x;

	for (x = 0; x < (month - 1); x++) {
		dayOfYear += months[x];
	}

	dayOfYear += day;

	if (((year % 4) == 0) && (month > 2)) {
		dayOfYear++;
	}

	return (dayOfYear);
}
