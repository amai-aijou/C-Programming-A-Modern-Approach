/******************************************
 * Name: prog8.c
 * Purpose: 
 * Author: jolson
 * Date: Sat May  3 08:07:26 PM CDT 2025
 ******************************************/

#include <stdio.h>

struct flight {
	int hDepartTime;
	int mDepartTime;
	int hArriveTime;
	int mArriveTime;
} flight_schedule[50];

int main(void) {
	
	int hInputTime, mInputTime, hDepartTime, mDepartTime, hArriveTime, mArriveTime;
	int inputMinutes, outputMinutes;
	char departAmPm, arriveAmPm;

	FILE *fp;
	char *filename = "flights.dat";
	char buffer[50];
	int i = 0, j = 0;;

	if ((fp = fopen(filename,"rb")) == NULL) {
		printf("Error: Could not open %s\n", filename);
	}

	//ask user for 24-hour time
	printf("Enter a 24-hour time: ");
	scanf("%d:%02d", &hInputTime, &mInputTime);

	//convert time to minute
	inputMinutes = (hInputTime * 60) + mInputTime;	

	// Used for debugging. uncomment to confirm times are correct
	//printf("hInputTime: %d\n mInputTime: %02d\n inputMinutes: %d\n", hInputTime, mInputTime, inputMinutes);

	//handle Out Of Range errors
	if (inputMinutes < 0 || inputMinutes >= 1440) {
			printf("Now you messed up! Now you messed up. You have messed up now. now you messed- u-erm, I mean...Out Of Range Error.\n");
			return 1;
	}

	// 22-13: New loop to find times!
	while ((fgets(buffer,sizeof(buffer),fp)) != NULL) {
		sscanf(buffer, "%d:%2d %d:%2d", &flight_schedule[i].hDepartTime, &flight_schedule[i].mDepartTime, &flight_schedule[i].hArriveTime, &flight_schedule[i].mArriveTime);
		i++;
	}


	for (j = 0 ; j < i ; j++ ) {

		if (((flight_schedule[j].hDepartTime * 60) + flight_schedule[j].mDepartTime) >= inputMinutes) {
			break;
		}

	}

	// If flight is later than last flight of the day, take the first one tomorrow!
	if (((flight_schedule[i-1].hDepartTime * 60) + flight_schedule[j].mDepartTime) < inputMinutes) {
		j = 0;
	}

	if (flight_schedule[j].hDepartTime >= 12) {
		departAmPm = 'p';
	} else {
		departAmPm = 'a';
	}

	if (flight_schedule[j].hArriveTime >= 12) {
		arriveAmPm = 'p';
	} else {
		arriveAmPm = 'a';
	}

	// Print the closest departure and arrival time
	printf("Closest departure time is %d:%02d %cm, arriving at %d:%02d %cm\n", flight_schedule[j].hDepartTime, flight_schedule[j].mDepartTime, departAmPm,
			flight_schedule[j].hArriveTime, flight_schedule[j].mArriveTime, arriveAmPm);

	// Special message if plane is leaving within a minute
	if ((((flight_schedule[j].hDepartTime * 60) + flight_schedule[j].mDepartTime) - inputMinutes) < 5) {
		if ((((flight_schedule[j].hDepartTime * 60) + flight_schedule[j].mDepartTime) - inputMinutes) >= 0) {
			printf("Hurry up, the plane is literally leaving NOW!\n");	
		}
	}

/*         CONVERT TO MINUTES
 * *************************************
 * Depart	Arrive		 DepartM ArriveM		
 * 8:00 am - 10:16 am 	=	480 - 616
 * 9:43 am - 11:52 am	=	583 - 712
 * 11:19 am - 1:31 pm	=	679 - 811 
 * 12:47 pm - 3:00 pm	=	767 - 900
 * 2:00 pm - 4:08 pm	=	840 - 968
 * 3:45 pm - 5:55 pm	=	945 - 1075
 * 7:00 pm - 9:20 pm	=	1140 - 1280
 * 9:45 pm - 11:58 pm	=	1305 - 1438
 *
 */ 
	return 0;
}
