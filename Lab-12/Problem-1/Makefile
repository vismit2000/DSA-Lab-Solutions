exe: driver.o extras.o graph.o
	gcc -o exe driver.o extras.o graph.o
	./exe
	rm -rf *o exe
driver.o: driver.c
	gcc -c driver.c
extras.o: extras.c
	gcc -c extras.c
graph.o: graph.c
	gcc -c graph.c