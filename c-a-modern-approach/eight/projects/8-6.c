/******************************************
 * Name: 8-6.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Wed Dec 31 07:57:37 PM CST 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

#define N 60
#define SIZE ((int) (sizeof(array) / sizeof(array[0])))

int main(void) {
	char ch;
	char array[N] = {0};
	int i = 0;

	printf("Enter message: ");
/*	
	for (i = 0; i < SIZE; i++) {
		scanf("%c", &array[i]);
	}
*/
	while ((ch = getchar()) != '\n') {
		array[i] = ch;
		i++;
	}

	printf("In Biffspeak: ");
	
	for (i = 0; i < SIZE; i++) {

		
		switch (toupper(array[i])) {
			case 'A': printf("4");
					  break;
			case 'B': printf("8");
					  break;
			case 'E': printf("3");
					  break;
			case 'I': printf("1");
					  break;
			case 'O': printf("0");
					  break;
			case 'S': printf("5");
					  break;
			case '\n': break;
			default: printf("%c", toupper(array[i]));
					 break;
		}
		
	}

	printf("!!!!!!!!!!\n");

return 0;

}
