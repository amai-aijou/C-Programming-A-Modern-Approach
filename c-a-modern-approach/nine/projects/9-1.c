/******************************************
 * Name: 9-1.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Fri Jan 23 08:56:08 PM CST 2026
 ******************************************/

#include <stdio.h>

// Set maximum number of discrete integers to accept
#define MAX 100

void selection_sort(int array[], int n);

int main(void) {

	int array[MAX] = {0};
	int n = 0;
	int x;
	int num = 1;

	printf("Please enter a series of integers: (0 to quit)");

	// Reads a series of integers until a zero is reached, and populates them in the array
	while (num != 0) {
		scanf("%d", &num);

		// Check again for zero (in case it was not added as part of first input)
		if (num == 0) {
			break;	
		}	

		array[n] = num;
		n++;
	}

	// Call function selection_sort() to re-order array in numerical order
	selection_sort(array, n);

	// Output array contents
	for (x = 0; x < n; x++) {
		printf("%d ", array[x]);
	}

	// Print new line so terminal cursor doesn't drive me crazy
	printf("\n");

	return 0;
}

// Receives Array and size of array. Starting size should be number of characters input by user
// Recursions will stop once n=1, since an n=0 loop would compare the first element to the first element, and is unnecessary
void selection_sort(int array[], int n){
	int largest = 0;
	int x;
	int part_element = n-1;
	
	// Find the largest element in the array, then assign to largest
	// When found, take note of which element it was found in
	for (x = 0; x < n; x++) {
		if (array[x] > largest) {
			largest = array[x];
			part_element = x;
		}
	}

	// Move value from end of array to the location where the largest was found; then, place the largest at the end
	array[part_element] = array[n-1];
	array[n-1] = largest;

	if (n  > 1) {
		selection_sort(array,n-1);
	}
}
