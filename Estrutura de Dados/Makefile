# -*- MakeFile -*-

all: doubly list queue

doubly: doubly_linked.h
	gcc -g -Wall main1.c doubly_linked.c -o doubly

list: list.h
	gcc -g -Wall main2.c list.c -o list

queue: priority_queue.h
	gcc -g -Wall main3.c priority_queue.c -o queue

clean:
	rm -f "doubly" "list" "queue"