/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-6.c (Previously Exercise 26-13.c)
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Nov  2 06:51:39 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

#define MAX_STR 1000

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void print_time(struct tm *time, char *format);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	time_t cur_time = time(NULL);
	struct tm *t = localtime(&cur_time);
	int hour = 0;
	char am_pm = 'a';

	printf("-------------------EXERCISE 26-13-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Apply the following strtime() formats to the current time\n\n");

	printf(COLOR_CYAN    "    %s\n", ctime(&cur_time)); 

	printf(COLOR_MAGENTA "(a) Sunday, June 3, 2007 05:48p\n" COLOR_RESET);
	print_time(t, "    %A, %B %d, %Y %R");
	printf("\n\n");

	printf(COLOR_MAGENTA "(b) Sun, 3 Jun 07 17:48\n" COLOR_RESET);
	print_time(t, "    %a, %d %b %y %R");
	printf("\n\n");

	printf(COLOR_MAGENTA "(c) 06/03/07 5:48:34 PM\n" COLOR_RESET);
	print_time(t, "    %D ");
	hour = t->tm_hour;
	if (hour >= 12) {
		hour -= 12;
		am_pm = 'p';
	} else {
		am_pm = 'a';
	}
	if (hour == 0) {
		hour = 12;
	}
	printf("%d:%d:%d%c\n\n", hour, t->tm_min, t->tm_sec, am_pm);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void print_time(struct tm *time, char *format) {

	char time_string[100];

	strftime(time_string, sizeof(time_string), format, time);

	printf("%s", time_string);
}
