main.o: main.c linkedlist.o
	gcc main.c build/linkedlist.o -o build/prog.out

linkedlist.o: linkedlist.c
	gcc linkedlist.c -c -o build/linkedlist.o