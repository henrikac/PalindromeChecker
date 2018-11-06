/*
 * Programmer: Henrik A. Christensen     Date Completed: 06-11-2018
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Write an iterativ function 'int is_palindrome_iter(char *str) that checks if str is a palindrome.
 *
 * Write a recursive function 'int is_palindrome_rec(char *str) that also checks if str is a palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[])
{
  char *word = NULL;

  if (argc == 2)
  {
    word = talloc(strlen(argv[1]) + 1);
    strcpy(word, argv[1]);
  }
  else
  {
    system(CLEAR);

    printf("====================\n");
    printf(" Palindrome Checker\n");
    printf("====================\n");

    do
    {
      printf("\nEnter a word: ");
      word = get_string(stdin);
    } while (strlen(word) < 1);
  }

  printf("\nIterative palindrome check: \"%s\" %s a palindrome", word, is_palindrome_iter(word) ? "is" : "is not");
  printf("\nRecursive palindrome check: \"%s\" %s a palindrome", word, is_palindrome_rec(word) ? "is" : "is not");
  printf("\n\n");

  if (word)
    free(word);

  return EXIT_SUCCESS;
}
