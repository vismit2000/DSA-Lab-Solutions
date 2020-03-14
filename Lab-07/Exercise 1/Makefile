all: target
target: main.o quick.o stack.o
	gcc -o exe main.o quick.o stack.o
	./exe 10000
	rm -rf *o exe
	
main.o: main.c
	gcc -c main.c
quick.o: quick.c
	gcc -c quick.c
stack.o: stack.c
	gcc -c stack.c