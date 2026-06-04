/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-13.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Jun  1 07:59:10 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct node {
	int value;
	int nodeNum;
	struct node *next;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);
void print_list(struct node *list);
struct node *create_linked_list_recursive(struct node *list, int numNodes);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct node *first = NULL;
	struct node *new_node = malloc(sizeof(struct node));
	int n = 5;

	printf("-------------------EXERCISE 17-13-------------------\n");

	first = create_linked_list_recursive(first, n);
	print_list(first);

	new_node->value = 20;
	new_node->nodeNum = 9;
	first = insert_into_ordered_list(first, new_node);
	print_list(first);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {

	struct node *cur = list, *prev = NULL;

	// Move ahead of every node that is smaller than new_node->value
	// 17-13: add "cur != NULL", because line 62 attempts to dereference via cur->next, which will crash if cur == NULL
	while (cur != NULL && cur->value <= new_node->value) {
		prev = cur;
		cur = cur->next;
	}

	// 17-13: Add logic if inserting before the very first node (if matching, inserts after final node matching number)
	if (prev == NULL) {
		new_node->next = cur;
		return new_node;
	}

	// Logic if inserting somewhere in the middle (this was already there)
	if (cur != NULL) {
		prev->next = new_node;
		new_node->next = cur;
	// 17-13: Add logic to insert at the very end
	} else if (cur == NULL) {
		prev->next = new_node;
		new_node->next = NULL;
	}

	return list;
}

void print_list(struct node *list) {

	struct node *p;


	for (p = list; p != NULL; p = p->next) {

		if (p != list) {
		printf("-> ");
		}

		printf("[%d.%d]", p->nodeNum, p->value);
	}

	printf("\n\n");
}

// I made it recursive because I'm ridiculous like that
// This time it's tail recursion, which reverses the order they're made; that way, the list is in order :)
struct node *create_ordered_list_recursive(struct node *list, int numNodes) {

	if (numNodes == 0) {
		return list;
	}

	struct node *new_node = malloc(sizeof(struct node));

	if (new_node == NULL) {
		printf("ERROR: Memory could not be allocated. Exiting to prevent null pointer!\n");
		exit(EXIT_FAILURE);
	}

	new_node->nodeNum = numNodes;
	new_node->value = (numNodes * 10);

	new_node->next = list;

	return create_linked_list_recursive(new_node, (numNodes - 1));
}
