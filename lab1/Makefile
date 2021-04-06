task1.2.o: task1.2.c
	gcc -c task1.2.c

task1.2: task1.2.o 
	gcc -o task task1.2.o 
	rm task1.2.o
	task

tests.o: tests.c
	gcc -c tests.c

tests: tests.o 
	gcc -o test tests.o
	rm tests.o

all: task1.2
