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

struct node {
	int value;
	struct node *next;
} 

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *create_linked_list_recursive(struct node *list, int numNodes);
void print_list(struct node *list);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct node *first;

	first = create_linked_list_recursive(first,5);


	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *delete_from_list_new(struct node *list, int n) {

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
	
	new_node->value = 30;

	if (numNodes > 1 ) {
		new_node->next = create_linked_list_recursive(new_node, (numNodes - 1));
	} else {
		new_node->value = 10;
	}

	new_node->nodeNum = numNodes;

	return new_node;
}

// Pointer to pointer allows us to alter the list directly within the function
void delete_from_list_new(struct node **list, int n) {

	struct node **p;

	for (p = list; p != NULL && (*p)->value != n; p = &(*p)->next) {
		;
	}

	if (*p != NULL) {
		free(*p);	
	}
}

/***************************
 
FIRST        **P
 50  -> 40 -> 30 -> 20 -> 10
        ^
       p->next = 20
****************************/










































// Pointer to pointer allows us to alter the list directly within the function
void add_to_list_new(struct node **list, int n) {

	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);

 92
	}

	new_node->value = n;
	new_node->next = *list;
	*list = new_node;

	printf("ADD entry %d to  list\n",(*list)->value);
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
