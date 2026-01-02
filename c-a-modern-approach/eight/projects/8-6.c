/******************************************
 * Name: 8-6.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Wed Dec 31 07:57:37 PM CST 2025
 ******************************************/

#include <stdio.h>
#define N 40
#define SIZE ((int) (sizeof(array) / sizeof(array[0])))

int main(void) {
	char ch;
	char array[N] = {0};

	printf("Enter message: ");
	
	for (i = 0; i < SIZE; i++) {
		scanf("%c", &Array[i]);
	}

	printf("In Biffspeak: ");
	
	for (i = 0; i < SIZE; i++) {

		switch (toupper(array[i])) {
			case 'A': printf("4");
			case 'B': printf("8");
			case 'E': printf("3");
			case 'I': printf("1");
			case 'O': printf("0");
			case 'S': printf("5");
			default: printf("%c", array[i]);
		}
		
	}

return 0;

}
