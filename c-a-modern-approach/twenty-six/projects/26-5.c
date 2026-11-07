/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Nov  7 01:30:00 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
time_t build_ctime(int mon, int mday, int year);
void print_time(struct tm *time, char *format);
int diff_days(time_t ct1, time_t ct2);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int mon1, mday1, year1, mon2, mday2, year2;
	time_t ct1, ct2;

	printf("***********************************\n");
	printf("*    Age Difference Calculator    *\n");
	printf("***********************************\n\n");


	printf("Enter the first date  (MM-DD-YYYY): ");
	scanf("%2d-%2d-%d", &mon1, &mday1, &year1);

	printf("Enter the second date (MM-DD-YYYY): ");
	scanf("%2d-%2d-%d", &mon2, &mday2, &year2);

	ct1 = build_ctime(mon1, mday1, year1);
	ct2 = build_ctime(mon2, mday2, year2);

	printf("\nThese two dates are %d day/s apart\n\n", diff_days(ct2, ct1));

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// "borrowed" from 26-4. Call it lazy if you like, but I'm learning to think like a programmer!
time_t build_ctime(int mon, int mday, int year)  {

	struct tm t;

	t.tm_mday = mday;
	t.tm_mon = (mon - 1);
	t.tm_year = year;
	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;
	t.tm_isdst = -1;

	return mktime(&t);
}

int diff_days(time_t ct1, time_t ct2) {

	int days_apart;
	time_t diff_secs;

	diff_secs = difftime(ct1, ct2);

	if ((days_apart = (((diff_secs / 60) / 60) / 24)) < 0) {
		days_apart = -days_apart;
	}

	return days_apart;
}

void print_time(struct tm *time, char *format) {

	char time_string[100];

	strftime(time_string, sizeof(time_string), format, time);

	printf("The new time is:\n\n%s\n\n", time_string);
}
