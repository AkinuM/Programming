task2.1: task2.1.c
	gcc -c task2.1.c
	gcc -o task task2.1.o 
	task
	rm task task2.1.o

tests: tests.c functions.c
	gcc -c functions.c
	gcc -c tests.c
	gcc -o test tests.o
	rm tests.o functions.o

all: task2.1