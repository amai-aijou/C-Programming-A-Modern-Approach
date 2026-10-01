/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-18.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Sep 28 08:29:09 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numbers[10000];
int count = 0;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void read_file(FILE *fp);
void print_array(void);
int compare_ints(const void *p, const void *q);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE *fp;
	int median;

	if ((fp = fopen(argv[1],"rb")) == NULL) {
		printf("Error: File %s could not be opened for reading. terminating.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(fp);
	qsort(numbers,count,sizeof(numbers[0]),compare_ints);


	if (count %2 == 0) {
		median = (numbers[(count / 2)] + numbers[(count/2-1)]) / 2;
	} else {
		median = numbers[(count / 2)];
	}

	printf("Smallest: %d\n", numbers[0]);
	printf("Largest: %d\n", numbers[count - 1]);
	printf("Median: %d\n", median);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void read_file(FILE *fp) {

	char buffer[30000];
	int i = 0;

	while (fgets(buffer, 30000, fp) != NULL){

		for (i = 0; buffer[i] != '\0'; i++) {

			while (buffer[i] == ' ') {
				i++;
			}

			if (buffer[i] == '\n') {
				break;
			}
			   
			if ((buffer[i] == '\n') || (sscanf((buffer + i), "%d", &numbers[count]) == 1)) {
				count++;
			} else {
				break;
			}

			while ((buffer[i] != ' ') && (buffer[i] != '\n')) {
				i++;
			}

		}

	}
}

void print_array(void) {
	int i = 0;

	printf("DEBUG - print all numbers:\n");
	for (i = 0; i < count; i++) {
		printf("%d\n", numbers[i]);
	}
}

int compare_ints(const void *p, const void *q) {

	const int *p1 = p;
	const int *q1 = q;

	if (*p1 < *q1) {
		return -1;
	} else if (*p1 == *q1) {
		return 0;
	} else {
		return 1;
	}
}
