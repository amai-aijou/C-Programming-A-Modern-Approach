stackADT2: stackADT2.o stackclient.o
	gcc -o stackADT2 stackADT2.o stackclient.o

stackADT.o: stackADT2.c stackADT2.h
	gcc -c stackADT2.c

stackclient.o: stackclient.c stackADT2.h
	gcc -c stackclient.c
