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
struct node *read_numbers(void);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
struct node *delete_from_list_new(struct node *list, int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct node *first = NULL;

	first = add_to_list(first, 10);
	first = add_to_list(first, 20);

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
		exist(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	return new_node;
}

// 17.6 pg. 438: add new with pointer to a pointer
// 
// **list breakdown:
// list     = the memory location of &first
// *list    = the value of first, which is the memory location of &new_node->next
// **list   = the current pointer value of new_node->next
// &(*list) = the memory location of &new_node->next
//
void node *add_to_list_new(struct node **list, int n) {

	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exist(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = *list;
	*list = new_node;
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
		return list;
	}

	if (prev == NULL) {
		list = list->next;
	} else {
		prev->next = cur->next;
	}

	free(cur);

	return list;
}

struct node *delete_from_list_new(struct node *list, int n) {

	//pointer to list->first, which is a pointer to the first list item
	struct node **p = &list->first;

	while ((*p != NULL) && ((*p)->value != n)) {
		p = &(*p)->next;
	}

	if (*p != NULL) {
		struct node *trash = p;
		*p = (*p)->next;
	}

	return *list;
}
