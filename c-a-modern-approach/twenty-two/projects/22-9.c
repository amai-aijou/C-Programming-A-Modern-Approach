/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-9.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Sep 16 06:29:51 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts[2];
int merged_parts;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
bool import_data(FILE *fp[*], char *argv[*]);
void sort_array(void);
void print_array(void);
bool export_data(FILE *fp, char *filename);
void merge_duplicates(void);
int compare_ints(const void *p, const void *q);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE * fp[3];
	int i;

	for (i = 0; i < 3; i++) {
		if ((fp[i] = fopen(argv[i+1], (i == 2? "wb":"rb"))) == NULL) {
			printf("Error: Could not open %s\n", argv[i+1]);
			exit(EXIT_FAILURE);
		}
	}

	import_data(fp, argv);

	printf("Starting Data:\n");
	print_array();

	sort_array();

	printf("Ending Data:\n");
	print_array();

	export_data(fp[2], argv[3]);

	// Close files and clean up when done!
	for (i = 0; i < 3; i++) {
		fclose(fp[i]);
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
bool import_data(FILE *fp[], char *argv[]) {

	int i, j;

	// Read inventory data into the arrays (with merged_parts as an offset)
	for (i = 0; i < 2; i++) {
		if ((num_parts[i] = fread(inventory + merged_parts, sizeof(inventory[0]),MAX_PARTS,fp[i])) == 0) {
			printf("Error: Data could not be read from file %s\n", argv[i+1]);
			return 0;
		}
		merged_parts += num_parts[i];
	}

	return 1;
}
bool export_data(FILE *fp, char *filename) {

	int i, j;
	int readOut = 0;

	if ((readOut = fwrite(inventory, sizeof(inventory[0]),merged_parts,fp)) != merged_parts) {
		printf("Error: Data could not be read to file %s\n", filename);
		return 0;
	}

	return 1;
}

// Uses Selection Sort (may remake as qsort eventually)
void sort_array(void) {

	int largest = 0, part_element;
	int i,j;

	// Sorts array in order
	qsort(inventory,merged_parts,sizeof(inventory[0]),compare_ints);


	// Remove duplicates
	for (i = 0; i < (merged_parts - 1); i++) {

		if (inventory[i].number == inventory[i+1].number) { 
			if (strcmp(inventory[i].name, inventory[i+1].name) == 0) {

				//printf("DEBUG - Duplicate found. Merging\n");
				inventory[i].on_hand += inventory[i+1].on_hand;

				// Moves all arrays down
				for (j = i+1; j < (merged_parts - 1); j++) {
					//printf("DEBUG - Deleting inventory[%d], replacing with inventory[%d]\n", j, j+1);
					inventory[j] = inventory[j+1];

				}

				inventory[merged_parts-1].number = 0;
				inventory[merged_parts-1].name[0] = 0;
				inventory[merged_parts-1].on_hand = 0;

				merged_parts -= 1;
				//printf("DEBUG - decremented merged_parts by 1: %d\n", merged_parts);
			} else {
				printf("Error: Part numbers match, but have conflicting names!\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

void print_array(void) {

	int i;


	// Print array (Potentially just for debug)
	for (i = 0; i < merged_parts; i++) {

		if (inventory[i].number == 0 && inventory[i].name[0] == 0 && inventory[i].on_hand == 0) {
			continue;
		}

		printf("[%d] | num: %d | name: %s | on hand: %d\n", i, inventory[i].number, inventory[i].name, inventory[i].on_hand);
	}
}

int compare_ints(const void *p, const void *q) {

	const struct part *p1 = p;
	const struct part *q1 = q;

	if (p1->number < q1->number) {
		return -1;
	} else if (p1->number == q1->number) {
		return 0;
	} else {
		return 1;
	}
}
