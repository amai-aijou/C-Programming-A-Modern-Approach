/******************************************
 * Name: 16-5.c (Formerly prog8.c from Chap. 5)
 * Purpose: 
 * Author: jolson
 * Date: Sat May  3 08:07:26 PM CDT 2025
 ******************************************/

#include <stdio.h>

#define MAX_FLIGHTS 8

// 16-5: departTime and arriveTime are integers that show the number of minutes that have elapsed since midnight
struct flight_times {
	int departTime;
	int arriveTime;
} daily_flights[MAX_FLIGHTS] =   {{ 480, 616},	// Depart  8:00am	Arrive 10:16am
					  			  { 583, 712},  // Depart  9:43am	Arrive 11:52am
								  { 679, 811},	// Depart 11:19am	Arrive  1:31pm
								  { 767, 900},	// Depart 12:47pm	Arrive  3:00pm
								  { 840, 968},	// Depart  2:00pm	Arrive  4:08pm
								  { 945,1075},	// Depart  3:45pm	Arrive  5:55pm
								  {1140,1280},	// Depart  7:00pm	Arrive  9:20pm
								  {1305,1438}};	// Depart  9:45pm	Arrive 11:58pm



int main(void) {
	
	int hInputTime, mInputTime, hDepartTime, mDepartTime, hArriveTime, mArriveTime;
	int inputMinutes, outputMinutes;
	char departAmPm, arriveAmPm;
	
	// 16-5 variables
	int i = 0;
	int newDepartTime = 0;
	int newArriveTime = 0;

	//ask user for 24-hour time
	printf("Enter a 24-hour time: ");
	scanf("%d:%02d", &hInputTime, &mInputTime);

	//convert time to minute
	inputMinutes = (hInputTime * 60) + mInputTime;	

	//handle Out Of Range errors
	if (inputMinutes < 0 || inputMinutes >= 1440) {
			printf("Now you messed up! Now you messed up. You have messed up now. now you messed- u-erm, I mean...Out Of Range Error.\n");
			return 1;
	}

	// 16-5: Create array of structs for departure and arrival times, then utilize
	i = 0;

	if (inputMinutes > daily_flights[(MAX_FLIGHTS - 1)].departTime) {
		newDepartTime = daily_flights[0].departTime;
		newArriveTime = daily_flights[0].arriveTime;
	}

	while (newDepartTime == 0) {
		if (i >= MAX_FLIGHTS) {
			i = 0;
		}

		if (daily_flights[i].departTime >= inputMinutes) {
			newDepartTime = daily_flights[i].departTime;
			newArriveTime = daily_flights[i].arriveTime;
		}

		i++;
	}

	hDepartTime = newDepartTime / 60;
	mDepartTime = newDepartTime % 60;
	hArriveTime = newArriveTime / 60;
	mArriveTime = newArriveTime % 60;

	if ((newDepartTime / 60) > 11) {
		departAmPm = 'p';
	} else {
		departAmPm = 'a';
	}

/*******************************************************************
 *                   OLD CODE
	//check times
	} else if ((inputMinutes <= 480) || inputMinutes >= 1305) {
			hDepartTime = 8; mDepartTime = 0;
			hArriveTime = 10; mArriveTime = 16;
			departAmPm = 'a'; arriveAmPm = 'a';
	} else if (inputMinutes >= 481 && inputMinutes <= 583) {
			hDepartTime = 9; mDepartTime = 43;
			hArriveTime = 11; mArriveTime = 52;
			departAmPm = 'a'; arriveAmPm = 'a';
	} else if (inputMinutes >= 584 && inputMinutes <= 679) {
			hDepartTime = 11; mDepartTime = 19;
			hArriveTime = 1; mArriveTime = 31;
			departAmPm = 'a'; arriveAmPm = 'p';
	} else if (inputMinutes >= 680 && inputMinutes <= 767) {
			hDepartTime = 12; mDepartTime = 47;
			hArriveTime = 3; mArriveTime= 0;
			departAmPm = 'p'; arriveAmPm = 'p';
	} else if (inputMinutes >= 768 && inputMinutes <= 840) {
			hDepartTime = 2; mDepartTime = 0;
			hArriveTime = 4; mArriveTime = 8;
			departAmPm = 'p'; arriveAmPm = 'p';
	} else if (inputMinutes >= 841 && inputMinutes <= 945) {
			hDepartTime = 3; mDepartTime = 45;
			hArriveTime = 5; mArriveTime = 55;
			departAmPm = 'p'; arriveAmPm = 'p';
	} else if (inputMinutes >= 946 && inputMinutes <= 1140) {
			hDepartTime = 7; mDepartTime = 0;
			hArriveTime = 9; mArriveTime = 20;
			departAmPm = 'p'; arriveAmPm = 'p';
	} else if (inputMinutes >= 1141 && inputMinutes <= 1305) {
			hDepartTime = 7; mDepartTime = 0;
			hArriveTime = 9; mArriveTime = 20;
			departAmPm = 'p'; arriveAmPm = 'p';
	}
 *
*******************************************************************/

	// Print the closest departure and arrival time
	printf("Closest departure time is %d:%02d %cm, arriving at %d:%02d %cm\n", hDepartTime, mDepartTime, departAmPm, hArriveTime, mArriveTime, arriveAmPm);

	// Special message if plane is leaving within a minute
	switch (inputMinutes) {
			case 480: case 583: case 679: case 767: case 840: case 945: case 1140: case 1305:	
				printf("Hurry up, the plane is literally leaving NOW!\n");	
				break;
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
