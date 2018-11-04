/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Write an iterativ function 'int is_palindrome_iter(char *str) that checks if str is a palindrome.
 *
 * Write a recursive function 'int is_palindrome_rec(char *str) that also checks if str is a palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

bool is_palindrome_iter(char *str);
bool is_palindrome_rec(char *str);

int main(void)
{
  int i;
  char *words[] = { "regninger", "paliniilap", "kajak" };

  for (i = 0; i < 3; i++)
  {
    printf("\n%s %s a palindrome", words[i], is_palindrome_rec(words[i]) ? "is" : "is not");
  }

  return EXIT_SUCCESS;
}

bool is_palindrome_iter(char *str)
{
  int i;
  size_t len_str = strlen(str);

  for (i = 0; i < len_str; i++)
    if (str[i] != str[(len_str - 1) - i])
      return false;

  return true;
}

bool is_palindrome_rec(char *str)
{
  char *new_str = NULL;
  size_t len_str = strlen(str);

  if (str[0] != str[len_str - 1])
    return false;
  else if (len_str > 3)
  {
    new_str = (char*)calloc(len_str - 1, sizeof(char));
    if (new_str == NULL)
    {
      printf("\nCouldn't allocate memory");
      exit(EXIT_FAILURE);
    }
    strncpy(new_str, &str[1], len_str - 2);
    return is_palindrome_rec(new_str);
  }

  if (new_str)
    free(new_str);
  
  return true;
}
