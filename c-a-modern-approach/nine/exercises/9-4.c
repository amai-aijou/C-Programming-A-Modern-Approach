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

	int dayOfYear = 0;

	switch (month) {
		case 12:
			dayOfYear += 31;
		case 11:
			dayOfYear += 30;
		case 10:
			dayOfYear += 31;
		case 9:
			dayOfYear += 30;
		case 8:
			dayOfYear += 31;
		case 7:
			dayOfYear += 31;
		case 6:
			dayOfYear += 30;
		case 5:
			dayOfYear += 31;
		case 4:
			dayOfYear += 30;
		case 3:
			dayOfYear += 31;
		case 2:
			dayOfYear += 28;
		case 1:
			dayOfYear += 31;
	}

	dayOfYear += day;

	dayOfYear = (dayOfYear + year) % 365;

	return (dayOfYear);
}
