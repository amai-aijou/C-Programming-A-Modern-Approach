
/******************************************
 * Name: prog2.c
 * Purpose: 
 * Author: jolson
 * Date: Mon Apr 21 06:29:36 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int itemNo;
	float unitPrice;
	int day, month, year;

	//22-12
	char *filename = "22-12.dat";
	char buffer[100];

	FILE *fp;

	if ((fp = fopen(filename,"r+")) == NULL) {
		printf("Error: File %s cannot be opened\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");	

	while (fgets(buffer,sizeof(buffer),fp) != NULL) {

		sscanf(buffer, "%d , %f , %d/%d/%d", &itemNo, &unitPrice, &month, &day, &year);	

		printf("%-d\t\t$ %7.2f\t%-d/%-d/%-d\n", itemNo, unitPrice, day, month, year);
	}

// SAMPLE 583,13.5,10/24/2005

/*************Chapter 3******************
	printf("Enter item number: ");
   	scanf("%d", &itemNo);	

	printf("Enter unit price: ");
	scanf("%f", &unitPrice);

	printf("Enter Purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &day, &month, &year);
	
	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");	
	printf("%-d\t\t$ %7.2f\t%-d/%-d/%-d\n", itemNo, unitPrice, day, month, year);
*************Chapter 3******************/

	return 0;
}
