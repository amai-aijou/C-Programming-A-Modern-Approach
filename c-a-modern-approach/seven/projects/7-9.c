/******************************************
 * Name: 7-9.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Sep 20 01:15:46 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

int main(void) {
	
	int hours, minutes;
	int milHours, milMinutes;
	char amPm, ch;

	// Prompt user for time.
	// Use scanf for digits
	printf("Enter a 12-hour time: ");
	scanf("%d:%d ", &hours, &minutes);
	
	// If input after time is a-Z, change to upper case and assign to amPm
	// Otherwise, display error message and end program 
	if ((ch = getchar()) >= 65 && ch <= 122 && hours >= 0 && hours <=12 &&  minutes >= 0 && minutes <=60) {
		amPm = toupper(ch);
	} else { 
		printf("ERROR: Invalid Entry. Enter 0-12:0-60, then AM or PM\n");
		return 1;
   	}

	// If PM, add 12 to hours; modulo 12 ensures 12am is 0 and 12pm is 12
	if (amPm == 'P') {
		milHours = ((hours % 12) + 12); 
		milMinutes = minutes;
	} else {
		milHours = (hours % 12);
		milMinutes = minutes;
	}

	// Print 24-hour time
	printf("Equivalent 24-hour time: %d:%02d\n", milHours, milMinutes);
	
	return 0;
}

