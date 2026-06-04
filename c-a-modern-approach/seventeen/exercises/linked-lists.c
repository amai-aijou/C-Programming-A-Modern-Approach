/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: linked-lists.c
   ❤︎︎࣪ Purpose: Stores an assortment of Linked List functions
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon May 25 04:27:05 PM CDT 2026
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
struct node *delete_from_list_test(struct node *list, int n);
struct node *add_to_list(struct node *list, int n);
void add_to_list_new(struct node **list, int n);
struct node *read_numbers(void);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
struct node *delete_from_list_new(struct node *list, int n);
struct node *create_linked_list_recursive(struct node *list, int numNodes);
struct node *create_ordered_list_recursive(struct node *list, int numNodes);
void print_list(struct node *list);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {
	printf("\n");

	struct node *first = NULL;

	// Add 10 to List
	first = add_to_list(first, 10);
	print_list(first);
	printf("\n\n");

	// Add 20 to list - new style
	add_to_list_new(&first, 20);
	print_list(first);
	printf("\n\n");

	// Add 30 to list
	first = add_to_list(first, 30);
	print_list(first);
	printf("\n\n");

	// Remove 30 to list
	first = delete_from_list_new(first, 30);
	print_list(first);
	printf("\n\n");

	// Remove 20 to list - new style
	first = delete_from_list_test(first, 20);
	print_list(first);

	printf("\n");
	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *delete_from_list_test(struct node *list, int n) {

	struct node **p = &list;

	while (*p != NULL && (*p)->value != n) {
		p = &(*p)->next;
	}

	if (*p != NULL) {
		printf("Deleting %d from list - I typed this version from memory :)\n", (*p)->value);
		struct node *temp = *p;
		*p = (*p)->next;
		free(temp);
	}

	return list;
}


struct node *add_to_list(struct node *list, int n) {

	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	printf("ADD entry %d to  list\n",new_node->value);

	return new_node;
}

// Pointer to pointer allows us to alter the list directly within the function
void add_to_list_new(struct node **list, int n) {

	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = *list;
	*list = new_node;

	printf("ADD entry %d to  list\n",(*list)->value);
}

struct node *read_numbers(void) {

	struct node *first = NULL;
	int n;

	printf("Enter a series of integers (0 to terminate): ");
	for (;;) {
		scanf("%d", &n);
		if (n == 0) {
			return first;
		}
		first = add_to_list(first, n);
	}
}

struct node *search_list(struct node *list, int n) {

	struct node *p;

	for (p = list; p != NULL; p = p->next) {
		if (p->value == n) {
			return p;
		}
		return NULL;
	}
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

// Exercise 17-6 - "Good taste" code from the master himself, Linus Torvalds!
struct node *delete_from_list_new(struct node *list, int n) {

	// Create a pointer to a pointer, aimed at the *list pointer's memory address
	struct node **p = &list;

	// Iterate through *p (the list) to find n. Stop if found
	while ((*p != NULL) && ((*p)->value != n)) {
		p = &(*p)->next;
	}

	// The while loop will only produce two results: NULL, or a pointer to the node with value n
	if (*p != NULL) {

		printf("DEL NODE %d\n",(*p)->value);

		// Create a temporary struct to hold the memory location of the node we wish to remove...
		struct node *trash = *p;

		// *p is the ->next value of the node *before* the bad one...(*p)->next is currently pointing at the good node after it
		// Now the ->next value of the node before the bad one, will point to the good one (creating a new chain without the bad node!)
		*p = (*p)->next;

		// Since *p no longer points to the bad node, *trash is the only remaining reference to the bad memory. Delete it!
		free(trash);

		// As we have directly altered the objects in the heap, we need only return a pointer to the first value in the list!
		return list;
	}

	//Fail: If *p is NULL, return list.  Since we used **p for the search, *list never changed :)
	printf("DEL NODE %d -- ERROR: NOT FOUND!\n", n);
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
