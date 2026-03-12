/******************************************
 * Name: 12-6.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Thu Jan 15 05:45:41 PM CST 2026
 ******************************************/

#include <stdio.h>

#define N 10

void quicksort_old(int a[], int low, int hihg);
int split_old(int a[], int low, int high);

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void) {

	int a[N], i;
	int *low = &a[0];
	int *high = &a[N - 1];

	printf("Enter %d numbers to be sorted: ", N);

	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

		quicksort(a, low, high);

		printf("In sorted order: ");

		for (i = 0; i < N; i++) {
			printf("%d ", a[i]);
		}

		printf("\n");

		return 0;
}

void quicksort(int a[], int *low, int *high) {

	int *middle;

	if (low >= high) {
		return ;
	}

	middle = split(a, low, high);
	quicksort(a, low, (middle - 1));
	quicksort(a, (middle + 1), high);

}

int *split(int a[], int *low, int *high) {

	int part_element = *low;

	for (;;) {
		while (low < high && part_element <= *high) {
			high--;
		}	
		if ( low >= high) {
			break;
		}
		*(low++) = *high;

		while (low < high && *low <= part_element) {
			low++;
		}
		if (low >= high) {
			break;
		}

		*(high--) = *low;
	}

	*high = part_element;

	return high;
}

/**************OLD PROGRAM**************
 
void quicksort_old(int a[], int low, int high) {
	
	int middle;

	if (low >= high) {
		return;
	}

	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int split_old(int a[], int low, int high) {

	int part_element = a[low];

	for (;;) {
		while (low < high && part_element <= a[high]) {
			high--;
		}
		if (low >= high) {
			break;
		}
		a[low++] = a[high];

		while (low < high && a[low] <= part_element) {
			low++;
		}
		if (low >= high) {
		   break;
		}

		a[high--] = a[low];
	}

	a[high] = part_element;

	return high;
}

**************OLD PROGRAM**************/
