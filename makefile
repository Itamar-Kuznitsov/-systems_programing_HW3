CC=gcc
FLAGS= -Wall -g

# compiling the whole program
all: isort.o txtfind.o isort txtfind

# making the execusion files:
txtfind: txtfind.o
	$(CC) $(FLAGS) txtfind.o -o txtfind

isort: isort.o 
	$(CC) $(FLAGS) isort.o -o isort


txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

isort.o: isort.c 
	$(CC) $(FLAGS) -c isort.c


.PHONY: clean make all

# deleting all .o + isort + txtfind(exe) fills
clean:
	rm -f *.o txtfind isort
	