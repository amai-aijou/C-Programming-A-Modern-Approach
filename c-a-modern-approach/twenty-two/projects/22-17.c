/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-17.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Sep 28 05:42:36 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE *fp;
	char buffer[MAX_LINE];
	long int num1, num2, num3;

	if ((fp = fopen(argv[1], "rb")) == NULL) {
		printf("Error: Could not open %s for reading.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Formatted numbers:\n");

	while (fgets(buffer, MAX_LINE, fp) != NULL) {

		//sscanf(buffer, "%3[0-9]%3[0-9]%4[0-9]", &num1, &num2, num3);
		if (sscanf(buffer, "%*[^0-9] %3d %*[^0-9] %3d %*[^0-9] %4d", &num1, &num2, &num3) != 3) {
			if (sscanf(buffer, "%3d %*[^0-9] %3d %*[^0-9] %4d", &num1, &num2, &num3) != 3) {
				if (sscanf(buffer, "%3d %*[^0-9] %3d %4d", &num1, &num2, &num3) != 3) {
					if (sscanf(buffer, "%3d %3d %4d", &num1, &num2, &num3) != 3) {
						printf("Houston, we have a problem\n");
						exit(EXIT_FAILURE);
					}
				}
			}
		}
		printf("(%d) %d-%d\n", num1, num2, num3);
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

