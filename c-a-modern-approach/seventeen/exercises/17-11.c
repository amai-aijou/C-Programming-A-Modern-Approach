/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-11.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 31 06:46:20 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int count_occurrences(struct node *list, int n);
struct node *create_linked_list_recursive(struct node *list, int numNodes);
void print_list(struct node *list);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct node *first = NULL;
	int n = 50;

	first = create_linked_list_recursive(first, 5);

	printf("Printing again after function: \n");
	print_list(first);

	printf("occurrences of %d: %d\n", n, count_occurrences(first, n));

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int count_occurrences(struct node *list, int n) {
	
	struct node **p;
	int counter = 0;

	for (p = &list; *p != NULL; p = &(*p)->next) {
		if ((*p)->value == n) {
			counter++;
			printf("DEBUG - HIT!\n");
		}
	}

	return counter;
}

// I made it recursive because I'm ridiculous like that
struct node *create_linked_list_recursive(struct node *list, int numNodes) {

	struct node *new_node = malloc(sizeof(struct node));
	
	if (new_node == NULL) {
		printf("ERROR: Memory could not be allocated. Exiting to prevent null pointer!\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->value = (numNodes * 10);

	if (numNodes > 1 ) {
		new_node->next = create_linked_list_recursive(new_node, (numNodes - 1));
	} else {
		print_list(list);
	}

	return new_node;
}

void print_list(struct node *list) {

	struct node *p;

	printf("[");
	for (p = list; p != NULL; p = p->next) {

		if (p != list) {
			printf(" -> ");
		}

		printf("%d", p->value);
	}
	printf("]");
	printf("\n\n");
}
