task2.2: task2.2.c
	gcc -c task2.2.c
	gcc -o task task2.2.o 
	task
	rm task task2.2.o

tests: tests.c functions.c
	gcc -c functions.c
	gcc -c tests.c
	gcc -o test tests.o
	rm tests.o functions.o

all: task2.2