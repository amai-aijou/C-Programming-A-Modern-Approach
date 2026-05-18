/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: inventory.c
   ❤︎︎࣪ Purpose: Maintains a parts database (array version)
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 10 07:50:57 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void menu(void);
void selection_sort();


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                

			Prompts the user to enter an operation code,
			then calls a function to perform the requested
			action. Repeats until the user enters the
			command 'q'. Prints an error message if the user
			enters an illegal code.
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char code;

	for (;;) {
		printf("Enter operation code (press m for menu): ");
		scanf(" %c", &code);
		while (getchar() != '\n') { 	// Skips to end of line
			;
		}

		switch (code) {
			case 'i': insert();
					  break;
			case 's': search();
					  break;
			case 'u': update();
					  break;
			case 'p': print();
					  break;
			case 'q': return 0;
			case 'm': menu();
					  break;
			default:  printf("Illegal code\n");
		}
		printf("\n");
	}
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
    ❤︎︎࣪ find_part			❤︎︎࣪       			❤︎︎࣪
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
    find_part: Looks up a part number in the inventory
   			   array. Returns the array index if the part
   			   number is found; otherwise, returns -1.
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int find_part(int number) {

	int i;

	for (i = 0; i < num_parts; i++) {
		if (inventory[i].number == number) {
			return i;
		}
	}
	return -1;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
    insert: Prompts the user for information about a new
			part and then inserts the part into the
			database. Prints an error message and returns
			prematurely if the part already exists or the
			database is full.
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void insert(void) {
	
	int part_number;

	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
    search: Prompts the user to enter a part number, then
    		looks up the part in the database. If the part
    		exists, prints the name and quantity on hand;
    		if not, prints an error message.
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void search(void) {

	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	} else {
		printf("Part not found.\n");	
	}
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
    update: Prompts the user to enter a part number.
    		Prints an error message if the part doesn't
    		exist; otherwise, prompts the user to enter
    		change in quantity on hand and updates the
    		database.
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void update(void) {

	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%dd", &change);
		inventory[i].on_hand += change;
	} else {
		printf("Part not found.\n");	
	}
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
    print: Prints a listing of all parts in the database,
		   showing the part number, part name, and
		   quantity on hand. Parts are printed in the
		   order in which they were entered into the
		   database.
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void print(void) {
	
	int i;

	// Sorts the inventory by number!
	selection_sort();

	printf("Part Number   Part Name		"
			"Quantity on Hand\n");
	for (i = 0; i < num_parts; i++) {
		printf("%7d		%-25s%11d\n", inventory[i].number,
				inventory[i].name, inventory[i].on_hand);
	}

}

void menu() {
	printf("OPTIONS\n");
	printf("i\tinsert\n");
	printf("s\tsearch\n");
	printf("u\tupdate\n");
	printf("p\tprint\n\n");

}

void selection_sort() {
	int i, j;
	int largest;
	int sort = num_parts;

	struct part largest_part;

	for (j = num_parts; j > 0; j--) {
		largest = 0;
		int part_element = j-1;

		for (i = 0; i < sort; i++) {
			if (inventory[i].number > largest) {
				largest = inventory[i].number;
				largest_part = inventory[i];
				part_element = i;
			}
		}

		inventory[part_element] = inventory[j-1];
		inventory[j-1] = largest_part;
		sort--;
	}
}

/*
void broken_selection_sort(struct part sorted_inventory[]) {
	int i,j;

	int number;
	char *name;
	int  on_hand;
	int sort = num_parts;

	for (j = num_parts; j > 0; j--) {
		int largest = 0;
		int part_element = j-1;

		for (i = 0; i < sort; i++) {
			if (sorted_inventory[i].number > largest) {
				largest = sorted_inventory[i].number;
				name = sorted_inventory[i].name;
				on_hand = sorted_inventory[i].on_hand;
				part_element = i;
			}
		}

		sorted_inventory[part_element].number = sorted_inventory[j-1].number;
		sorted_inventory[part_element].name = sorted_inventory[j-1].name;
		sorted_inventory[part_element].on_hand = sorted_inventory[j-1].on_hand;

		sorted_inventory[j-1].number = largest;
		sorted_inventory[j-1].name = name;
		sorted_inventory[j-1].on_hand = on_hand;
		sort--;

	}
}
*/
