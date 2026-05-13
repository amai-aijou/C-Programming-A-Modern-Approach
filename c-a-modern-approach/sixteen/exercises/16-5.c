/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed May 13 11:23:18 AM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
} d1 = {5, 6, 2007},
  d2 = {8, 9, 2003};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("D1 vs D2: %d\n", compare_dates(d1,d2));
	printf("If this works, it should print -1, as d1 is 2007, and d2 is 2003!\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// (a) Returns the day of the year that corresponds to the date d
int day_of_year(struct date d) {

	int days = 0, x;

	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (x = 0; x < (d.month - 1); x++) {

		days += months[x];
	}

	days += d.day;

	if (d.year % 4 == 0) {
		days++;
	}

	return days;
}

// (b) Compares two dates and returns +1 if d1 is greater, -1 is less than, and 0 if same
int compare_dates(struct date d1, struct date d2) {
	if ((day_of_year(d1)) > (day_of_year(d2))) {
		return 1;
	} else if (day_of_year(d2) > day_of_year(d1)) {
		return -1;
	} else if (day_of_year(d1) == day_of_year(d2)) {
		return 0;
	} else {
		return 500;
	}
}
