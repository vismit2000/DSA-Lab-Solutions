exe: main.o qsort.o
	gcc -o exe main.o qsort.o
	./exe input.txt
	rm -rf *o exe
	
main.o: main.c
	gcc -c main.c
qsort.o: qsort.c
	gcc -c qsort.c