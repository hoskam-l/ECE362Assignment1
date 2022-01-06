main: main.o 
	gcc -std=c99 -Wall -pedantic main.o -o main

help:
	@echo To find the highest value add -h to the list of values
	@echo To find the lowest value add -l to the list of values
	@echo To sort the list don\'t add any modifiers to the list

test:
	./main.exe zebra apple horse orange rat
	./main.exe zebra apple horse orange rat -h
	./main.exe zebra -h apple horse orange rat
	./main.exe zebra apple horse orange rat -l
	./main.exe zebra apple horse -l orange rat
	./main.exe -h
	./main.exe -l 
	
main.exe: main.c
	gcc -c main.c 

all : clean clearscr main test 

clearscr: 
	clear
clean: 
	rm -f *.o *.exe 