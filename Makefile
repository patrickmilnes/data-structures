main: linkedlist.o utils.o
	gcc src/main.c build/linkedlist.o build/utils.o -o build/prog

linkedlist.o: src/linkedlist.c
	gcc src/linkedlist.c -c -o build/linkedlist.o

utils.o: src/utils.c
	gcc src/utils.c -c -o build/utils.o