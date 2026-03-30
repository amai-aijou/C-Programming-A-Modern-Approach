/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 13-2.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Mar 12 09:33:11 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int read_line(char str[], int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char reminders[MAX_REMIND][MSG_LEN+3];
	char day_time_str[9], msg_str[MSG_LEN+1], day_time[10];
	int day, hour, minute, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter date, time, and reminder: ");
		scanf("%2d %2d:%02d", &day, &hour, &minute);
		printf("day: %d | hour: %d | minute: %d\n", day, hour, minute);

		if (day == 0) {
			break;

		} else if ((day < 0) || (day > 31)) {

			printf("Error: Day must be between 0 and 31.\n");
			while (getchar() != '\n') {
				;
			}
			continue;
		}

		printf("-----1: reminders[%d]: |%s|\n", i, reminders[i]);
		sprintf(day_time_str, "%2d %2d:%02d", day, hour, minute);
		printf("sprint day_time_str: %s\n", day_time_str);
		//sprintf(time_str, "%2d:%02d", hour, minute);
		printf("read_line chars: %d\n", read_line(msg_str, MSG_LEN));
		printf("after read_line - msg_str: |%s|\n", msg_str);
		printf("-----2: reminders[%d]: |%s|\n", i, reminders[i]);

		// Run through reminders[] til you hit the first day that is larger than day_str.
		// Sorts by date, then stores the proper location in variable i
		for (i = 0; i < num_remind; i++) {
			printf("DEBUG - daystr: |%s| reminders[%d]: |%s|\n", day_time_str, i, reminders[i]);
			if (strcmp(day_time_str, reminders[i]) < 0) {
				printf("day_str is smaller than reminders[%d]\n", i);
				break;
			}
		}

		printf("-----3: reminders[%d]: |%s|\n", i, reminders[i]);
		// Now sort by time

		// move each reminder after the day in question down one entry to make a hole for the new entry
		for (j = num_remind; j > i; j--) {
			printf("\nBEFORE MOVING NUMBERS:\nreminders[%d]: |%s| reminders[%d-1]: |%s|\n", j, reminders[j], j, reminders[j-1]);
			strcpy(reminders[j], reminders[j-1]);
			printf("AFTER MOVING NUMBERS:\nreminders[%d]: |%s| reminders[%d-1]: |%s|\n\n", j, reminders[j], j, reminders[j-1]);
		}

		printf("reminders[%d]: |%s|\n", i, reminders[i]);
		strcpy(reminders[i], day_time_str);
		printf("reminders[%d] after day_time_str copy: |%s|\n", i, reminders[i]);
		//strcat(reminders[i], time_str);
		strcat(reminders[i], msg_str);
		printf("reminders[%d] after masg_str copy: |%s|\n\n", i, reminders[i]);

		num_remind++;
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int read_line(char str[], int n) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
