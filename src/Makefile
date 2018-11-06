# Compilation of main

CFLAGS = -ansi -pedantic -Wall
TARGET = main

$(TARGET).exe: palindrome.o  $(TARGET).c
	gcc $(CFLAGS) -o $(TARGET) palindrome.o $(TARGET).c

palindrome.o: palindrome.h palindrome.c
	gcc -c palindrome.c
