19-2: 19-2.o client.o
	gcc -o 19-2 19-2.o client.o

19-2.o: 19-2.c 19-2.h
	gcc -c 19-2.c

client.o: client.c 19-2.h
	gcc -c client.c
