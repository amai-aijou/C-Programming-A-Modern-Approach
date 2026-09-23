/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-11.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tue Sep 22 04:55:05 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

char *months[12] = {"January", "February", "March", "April", "May", "June", "July",
					"August", "September", "October", "November", "December"};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	int nDay, nMonth, nYear;

	if ((sscanf(argv[1], "%2d-%2d-%4d", &nMonth, &nDay, &nYear)) < 3) {
		if ((sscanf(argv[1], "%2d/%2d/%4d", &nMonth, &nDay, &nYear)) == 0) {
			printf("Error: Format is unrecognized. Please use 9/20/1988 or 9-20-1988!\n");
			exit(EXIT_FAILURE);
		}
	}

	nMonth = ((nMonth - 1) % 13 + 1) - 1;
	nDay = (nDay - 1) % 32 + 1;
	if (nDay == 0) {
		nDay++;
	}

	if (nYear < 100) {
		nYear + 2000;
	}

	printf("%s %d, %4d\n", months[nMonth], nDay, nYear);

	return 0;
}

