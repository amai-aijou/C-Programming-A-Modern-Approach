/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: queueADT.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Jul  6 11:35:01 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueADT.h"

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *top;
	struct node *tail;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
static void terminate(const char *message) {

	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create_queue(void) {

	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL) {
		terminate("Error in create: queue could not be created.");
	}
	q->top = NULL;
	q->tail = NULL;

	return q;
}

void destroy_queue(Queue q) {
	make_empty(q);
	free(q);
}

void make_empty(Queue q) {

	int x;

	while (!is_empty(q)) {
		remove_queue(q);
	}

	q->top = 0;
	q->tail = 0;
}

bool is_empty(Queue q) {

	return q->top == NULL;
}

void insert_queue(Queue q, Item x) {

	struct node *new_node = malloc(sizeof(struct node));
	if (q == NULL) {
		terminate("Error in create: queue could not be created.");
	}

	if (q->tail == NULL) {
		new_node->data = x;
		new_node->next = NULL;
		q->top = new_node;
		q->tail = new_node;
		return;
	}

	new_node->data = x;
	new_node->next = NULL;
	q->tail->next = new_node;
	q->tail = new_node;
}

Item remove_queue(Queue q) {

	Item num = q->top->data;
	struct node *old_top = q->top;

	if (is_empty(q)) {
		terminate("Error in remove_queue: queue is empty!\n");
	}

	q->top = old_top->next;
	free(old_top);

	return num;
}

Item return_first(Queue q) {

	return q->top->data;
}

Item return_last(Queue q) {

	return q->tail->data;
}

void print_queue(Queue q) {

	struct node *p;

	printf("\nCurrent Queue Contents:\n");
	printf("{");

	for (p = q->top; p != NULL; p = p->next) {

		if (p != q->top) {
			printf(" -> ");
		}

		printf("[%d]", p->data);
	}
	printf("}");
	printf("\n\n");
}
