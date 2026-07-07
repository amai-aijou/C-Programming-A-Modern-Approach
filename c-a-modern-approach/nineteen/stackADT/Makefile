stackADT: stackADT.o stackclient.o
	gcc -o stackADT stackADT.o stackclient.o

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c

stackclient.o: stackclient.c stackADT.h
	gcc -c stackclient.c
