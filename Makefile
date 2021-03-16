task1.2.o: task1.2.c
	gcc -c task1.2.c

task1.2: task1.2.o 
	gcc -o task task1.2.o 
	rm task1.2.o
	task

all: task1.2