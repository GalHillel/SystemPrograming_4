all: graph

graph: main.c nodes.c edges.c queue.c graph.c
	gcc -Wall -g main.c nodes.c edges.c queue.c graph.c -o graph

.PHONY: clean all

clean:
	rm -f *.o *.a *.so graph