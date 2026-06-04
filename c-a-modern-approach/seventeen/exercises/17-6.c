/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-6.c
   ❤︎︎࣪ Purpose: 
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
struct node *add_to_list(struct node *list, int n);
struct node *generate_list(void);
void *print_list(struct node *list);
struct node *delete_from_list(struct node *list, int n);
struct node *delete_from_list_new(struct node *list, int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct node *first = NULL;

	printf("-------------------EXERCISE 17-6-------------------\n");
	printf("Note: all nodes added to front of list\n\n");

	// Generate linked list with a few sample numbers
	first = generate_list();

	// Remove 30 from list using standard method
	first = delete_from_list_new(first, 20);
	print_list(first);

	// Remove 20 from list -- Exercise 17-6
	first = delete_from_list_new(first, 10);
	print_list(first);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct node *add_to_list(struct node *list, int n) {

	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	printf("ADD NODE %d\n",new_node->value);
	print_list(new_node);

	return new_node;
}

struct node *generate_list(void) {

	struct node *first = NULL;

	int linked_list[3] = {10,20,30};
	int *p, n = 3;


	for (p = linked_list; p < (linked_list + n); p++) {
		first = add_to_list(first, *p);
	}

	return first;
}

void *print_list(struct node *list) {

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

struct node *delete_from_list(struct node *list, int n) {

	struct node *cur, *prev;

	for (cur = list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next) {
		;
	}

	if (cur == NULL) {
		printf("DEL NODE %d -- ERROR: NOT FOUND!\n", n);
		return list;
	}

	if (prev == NULL) {
		printf("DEL NODE %d\n",list->value);
		list = list->next;
	} else {
		printf("DEL NODE %d\n",prev->value);
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
