task4.1: task4.1.c
	gcc -c task4.1.c
	gcc -o task task4.1.o 
	task
	rm task task4.1.o

tests: tests.c functions.c
	gcc -c functions.c
	gcc -c tests.c
	gcc -o test tests.o
	rm tests.o functions.o

all: task4.1