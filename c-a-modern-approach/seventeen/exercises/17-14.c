/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-14.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Jun  3 08:43:52 PM CDT 2026
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
void delete_from_list_void(struct node **list, int n);
struct node *delete_from_list(struct node *list, int n);
struct node *create_linked_list_recursive(struct node *list, int numNodes);
void print_list(struct node *list);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct node *first;

	printf("-------------------EXERCISE 17-14-------------------\n");

	first = create_linked_list_recursive(first,5);
	print_list(first);

	first = delete_from_list(first, 30);
	print_list(first);

	delete_from_list_void(&first, 50);
	print_list(first);

	printf("Tested: Deleting first node from list, last node from list, middle node.\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void delete_from_list_void(struct node **list, int n) {

	struct node *cur, *prev;

	for (cur = *list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next) {
		;
	}

	if (cur == NULL) {
		printf("DELETE entry %d from list -- NOT FOUND!\n", n);
	}

	if (prev == NULL) {
		printf("DELETE entry %d from list\n",(*list)->value);
		*list = (*list)->next;
	} else {
		printf("DELETE entry %d from list\n",prev->value);
		prev->next = cur->next;
	}

	free(cur);
}

struct node *delete_from_list(struct node *list, int n) {

	struct node *cur, *prev;

	for (cur = list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next) {
		;
	}

	if (cur == NULL) {
		printf("DELETE entry %d from list -- NOT FOUND!\n", n);
		return list;
	}

	if (prev == NULL) {
		printf("DELETE entry %d from list\n",list->value);
		list = list->next;
	} else {
		printf("DELETE entry %d from list\n",prev->value);
		prev->next = cur->next;
	}

	free(cur);

	return list;
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
