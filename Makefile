main: linkedlist.o
	gcc src/main.c build/linkedlist.o -o build/prog

linkedlist.o: src/linkedlist.c
	gcc src/linkedlist.c -c -o build/linkedlist.o