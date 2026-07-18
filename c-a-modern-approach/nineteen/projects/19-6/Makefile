queueADT: queueADT.o queueclient.o
	gcc -o queueADT queueADT.o queueclient.o

queueADT.o: queueADT.c queueADT.h
	gcc -c queueADT.c

queueclient.o: queueclient.c queueADT.h
	gcc -c queueclient.c
