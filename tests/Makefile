# Compilation of tests

CFLAGS = -ansi -pedantic -Wall
TARGET = test

$(TARGET).exe: ../src/palindrome.o AllTests.c CuTest.c IsPalindromeIterTest.c IsPalindromeRecTest.c
	gcc $(CFLAGS) ../src/palindrome.o AllTests.c CuTest.c IsPalindromeIterTest.c IsPalindromeRecTest.c \
		-o test

../src/palindrome.o: ../src/palindrome.h ../src/palindrome.c
	gcc -c ../src/palindrome.c
