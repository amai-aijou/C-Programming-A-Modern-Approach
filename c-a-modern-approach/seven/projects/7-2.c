
/******************************************
 * Name: square2.c
 * Purpose: 
 * Author: jolson
 * Date: Tue Jun  3 04:30:59 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	int i, n;
	char ch; 

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		printf("%10d%10d\n", i, i * i);

		if (i % 24 == 0) {
			printf("Press Enter to continue...\n");
			while (ch != '\n') {
				scanf("%c", &ch);
				ch = getchar();
			}
		}
	}

	return 0;
}
