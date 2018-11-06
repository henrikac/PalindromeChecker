# Compilation of tests

CFLAGS = -ansi -pedantic -Wall
TARGET = test
TESTFILES = AllTests.c CuTest.c IsPalindromeIterTest.c IsPalindromeRecTest.c GetStringTest.c

$(TARGET).exe: ../src/palindrome.o $(TESTFILES)
	gcc $(CFLAGS) ../src/palindrome.o $(TESTFILES) \
		-o test

../src/palindrome.o: ../src/palindrome.h ../src/palindrome.c
	gcc -c ../src/palindrome.c
