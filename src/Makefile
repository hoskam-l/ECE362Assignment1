main: main.o 
	gcc -std=c99 -Wall -pedantic main.o -o main.exe

help:
	@echo To find the highest value add -h to the list of values
	@echo To find the lowest value add -l to the list of values
	@echo To sort the list don\'t add any modifiers to the list

test:
	./main zebra apple horse orange rat
	./main zebra apple horse orange rat -h
	./main zebra -h apple horse orange rat
	./main zebra apple horse orange rat -l
	./main zebra apple horse -l orange rat
	./main zebra apple -h horse -l orange rat
	./main -h
	./main -l 
	
main.exe: main.c
	gcc -c main.c 

all : clean clearscr main test 

clearscr: 
	clear
clean: 
	rm -f *.o *.exe 
