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
	int nodeNum;
	struct node *next;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *find_last(struct node *list, int n);
struct node *create_linked_list_recursive(struct node *list, int numNodes);
void print_list(struct node *list);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 17-12-------------------\n");

	struct node *first = NULL;
	struct node *last;
	int n = 30;

	first = create_linked_list_recursive(first, 5);

	printf("Printing current linked list: \n");
	print_list(first);

	last = find_last(first, n);
	printf("last occurrence of %d: [#%d: %d]\n", n, last->nodeNum, last->value);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *find_last(struct node *list, int n) {
	
	struct node **p;
	struct node *last;

	for (p = &list; *p != NULL; p = &(*p)->next) {
		if ((*p)->value == n) {
			last = *p;
		}
	}

	if (last != NULL) {
		return last;
	} else {
		return NULL;
	}
}

// I made it recursive because I'm ridiculous like that
struct node *create_linked_list_recursive(struct node *list, int numNodes) {

	struct node *new_node = malloc(sizeof(struct node));
	
	if (new_node == NULL) {
		printf("ERROR: Memory could not be allocated. Exiting to prevent null pointer!\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->value = 30;

	if (numNodes > 1 ) {
		new_node->next = create_linked_list_recursive(new_node, (numNodes - 1));
	} else {
		new_node->value = 10;
	}

	new_node->nodeNum = numNodes;

	return new_node;
}

void print_list(struct node *list) {

	struct node *p;

	printf("[");
	for (p = list; p != NULL; p = p->next) {

		if (p != list) {
			printf(" -> ");
		}

		printf("#%d.[%d]", p->nodeNum, p->value);
	}
	printf("]");
	printf("\n\n");
}
