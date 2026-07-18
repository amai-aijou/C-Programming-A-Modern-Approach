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

#define QUEUE_SIZE 100

struct queue_type {
	Item contents[QUEUE_SIZE];
	int top;
	int tail;
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
	q->top = 0;
	q->tail = 0;

	return q;
}

void destroy_queue(Queue q) {
	free(q);
}

void make_empty(Queue q) {

	int x;

	// Manually set all queue elements to 0
	for (x = 0; x < QUEUE_SIZE; x++) {
		q->contents[x] = 0;
	}
	q->top = 0;
	q->tail = 0;
}

bool is_empty(Queue q) {

	return q->tail == q->top;
}

void insert_queue(Queue q, Item x) {

	q->contents[q->tail] = x;

	q->tail = (q->tail + 1) % QUEUE_SIZE;
}

Item remove_queue(Queue q) {

	Item num = q->contents[q->top];

	q->top = (q->top + 1) % QUEUE_SIZE;

	return num;
}

Item return_first(Queue q) {

	return q->contents[q->top];
}

Item return_last(Queue q) {

	return q->contents[q->tail - 1];
}

void print_queue(Queue q) {

	int x;

	printf("\nCurrent Queue Contents:\n");

	for (x = q->top; x < q->tail; x++) {

		printf("%d",q->contents[x]);

		if (x < (q->tail - 1)) {
			printf(" -> ");
		}
	}
	printf("\n\n");
}
