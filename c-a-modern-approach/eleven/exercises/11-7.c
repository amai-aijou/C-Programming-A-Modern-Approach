/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name:  
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tue Feb 17 06:52:22 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void split_date(int day_of_year, int year, int *month, int *day);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int day_of_year, year;
	int day = 0, month = 0;

	printf("Please enter the day of year: ");
	scanf("%d", &day_of_year);

	printf("Please enter the year: ");
	scanf("%d", &year);

	// Error handling
	if (((year %4) == 0) && (day_of_year == 366)) {
		printf("This is not a leap year. Max days: 365\n");
		exit(EXIT_FAILURE);
	}

	// Run function to split date into month and day
	split_date(day_of_year, year, &month, &day);

	// Print month and day
	printf("Date is January %d %d\n", day, month);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void split_date(int day_of_year, int year, int *month, int *day) {

	int i;

	// If a leap year, there are 366 days, and the 60th day is Feb 29th
	if ((year % 4) == 0) {
		months[1] += 1;
	}
	

	for (i = 0; i < (12); i++) {

		if (day_of_year - months[i] > 0) {
			day_of_year -= months[i];
			(*month)++; 
		} else break;

	}

	*day = day_of_year;

}
