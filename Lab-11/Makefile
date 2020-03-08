exe: main.o trie.o
	gcc -o exe main.o trie.o
	./exe input
	rm -rf *o exe

main.o: main.c
	gcc -c main.c
trie.o: trie.c
	gcc -c trie.c