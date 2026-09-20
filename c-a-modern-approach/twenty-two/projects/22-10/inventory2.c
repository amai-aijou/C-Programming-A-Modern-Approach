/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: inventory2.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 24 05:42:50 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct part *next;
};

struct part *inventory = NULL;


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct part *find_part(int number);
bool dump(void);
bool restore(void);
void insert(void);
void search(void);
void update(void);
void print(void);

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
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') {	/* skips to end of line */
			;
		}

		switch (code) {
			case 'd': dump();
					  break;
			case 'i': insert();
					  break;
			case 'r': restore();
					  break;
			case 's': search();
					  break;
			case 'u': update();
					  break;
			case 'p': print();
					  break;
			case 'q': return 0;
			default:  printf("Illegal code\n");
		}
		printf("\n");
	}
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    

				❤︎︎࣪ find_part			❤︎︎࣪ insert
				❤︎︎࣪ update			❤︎︎࣪ print
				❤︎︎࣪ dump				❤︎︎࣪ restore

  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

//22-8: Dumps database to a file
bool dump(void) {

	FILE *fp;
	char filename[255];
	int user_tries = 0;
	int offset = 0;

	struct part *p;

	printf("\nNote: if file does not exist, it will be created; otherwise, contents will be overwritten.\n\n");
	printf("Enter name of output file: ");
	scanf("%s", &filename);

	while (((fp = fopen(filename,"wb")) == NULL) && (user_tries < 3)) {
		printf("Error: Database file could not be opened! Please try again.\n");
		user_tries++;
	}

	if (user_tries >= 3) {
		printf("Failed opening database, aborting function.\n");
		return;
	}

	for (p = inventory; p != NULL; p = p->next) {

		if ((fwrite(inventory + offset,sizeof(struct part),1,fp)) == 0) {
			printf("Error: Database backup could not be created. Stalled at offset %d\n", offset);
			return;
		} else {
			printf("Success! Database has been written to %s\n", filename);
		}

		offset++;

	}


	/*
	if ((fwrite(inventory,sizeof(inventory[0]),num_parts,fp)) < num_parts) {
		printf("Error: Database backup could not be created.\n");
		return;
	} else {
		printf("Success! Database has been written to %s\n", filename);
	}
	*/

	fclose(fp);
}

//22-8: restores database from a file
bool restore(void) {

	FILE *fp;
	char filename[255];
	int n;

	printf("Enter name of file to be restored: ");
	scanf("%s", &filename);

	while ((fp = fopen(filename,"rb")) == NULL) {
		printf("Error: Database file not found! Please try again (0 to cancel)\n");
		if (filename == "0") {
			return;
		}
	}
/*
	if ((n = (fread(inventory,sizeof(inventory[0]),MAX_PARTS,fp))) == 0) {
		printf("Error: Database backup could not be restored. Ensure file is not empty!\n");
	*/
}

/************************************************************
 *  find_part: Looks up a part number in the inventory		*
 * 			   array. Returns a pointer to the node			*
 * 			   containing the part number; if the part		*
 * 			   number is not found, returns NULL.			*
 ************************************************************/
struct part *find_part(int number) {

	struct part *p;

	for (p = inventory;
		 p != NULL && number > p->number;
		 p = p->next) {
		;
	}
	if (p != NULL && number == p->number) {
		return p;
	}
	return NULL;
}

/************************************************************
 *  insert: Prompts the user for information about a new	*
 *			part and then inserts the part into the			*
 *			inventory list; the list remains sorted by		*
 *			part number. Prints an error message and		*
 *			returns	prematurely if the part already exists	*
 *			or space could not be allocated for the part.	*
 ************************************************************/
void insert(void) {

	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);

	for (cur = inventory, prev = NULL;
		 cur != NULL && new_node->number > cur->number;
		 prev = cur, cur = cur->next) {
		;
	}
	if (cur != NULL && new_node ->number == cur->number) {
		printf("Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);

	new_node->next = cur;
	if (prev == NULL) {
		inventory = new_node;
	} else {
		prev->next = new_node;
	}
}

/************************************************************
 *  search: Prompts the user to enter a part number, then	*
 *  		looks up the part in the database. If the part	*
 *  		exists, prints the name and quantity on hand;	*
 *  		if not, prints an error message.				*
 ************************************************************/
void search(void) {

	int number;
	struct part *p;
	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	} else {
		printf("Part not found.\n");
	}
}

/************************************************************
 *  update: Prompts the user to enter a part number.		*
 *  		Prints an error message if the part doesn't		*
 *  		exist; otherwise, prompts the user to enter		*
 *  		change in quantity on hand and updates the		*
 *  		database.										*
 ************************************************************/
void update(void) {

	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	} else {
		printf("Part not found.\n");
	}
}

/************************************************************
 *  print: Prints a listing of all parts in the database,	*
 *		   showing the part number, part name, and			*
 *		   quantity on hand. Part numbers will appear in	*
 *		   ascending order.									*
 ************************************************************/
void print(void) {

	struct part *p;

	printf("Part Number   Part Name		"
			"Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next) {
		printf("%7d		%-25s%11d\n", p->number, p->name,
				p->on_hand);
	}
}
