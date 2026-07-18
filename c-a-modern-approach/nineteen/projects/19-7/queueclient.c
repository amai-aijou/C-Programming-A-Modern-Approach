/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: queueclient.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Jul 17 06:09:01 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include "queueADT.h"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	Queue q1, q2;
	int n;

	q1 = create_queue();
	q2 = create_queue();

	n = 1;
	insert_queue(q1, n);
	printf("Inserted %d into q1 queue\n", n);

	n = 2;
	insert_queue(q1, n);
	printf("Inserted %d into q1 queue\n", n);

	print_queue(q1);

	n = remove_queue(q1);
	printf("Removed %d from q1 queue\n", n);

	insert_queue(q2, n);
	printf("Inserted %d into q2 queue\n", n);

	n = remove_queue(q1);
	printf("Removed %d from q1 queue\n", n);

	insert_queue(q2, n);
	printf("Inserted %d into q2 queue\n", n);

	destroy_queue(q1);
	printf("Destroyed q1 queue\n\n");

	printf("Removing all from q2 (client operation):\n");
	while (!is_empty(q2)) {
		printf("Removed %d from s2 queue\n", remove_queue(q2));
	}

	n = 3;
	insert_queue(q2, n);
	printf("Inserted %d into q2 queue\n", n);

	print_queue(q2);
	make_empty(q2);

	if (is_empty(q2)) {
		printf("Queue q2 is empty!\n");
	} else {
		printf("Queue q2 is not empty\n");
	}

	destroy_queue(q2);
	printf("Destroyed q2 queue\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

