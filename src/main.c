/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt N�rmark              Class:          Imperative Programming
 *
 * Write an iterativ function 'int is_palindrome_iter(char *str) that checks if str is a palindrome.
 *
 * Write a recursive function 'int is_palindrome_rec(char *str) that also checks if str is a palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef enum { false, true } bool;

bool is_palindrome_iter(char *str);
bool is_palindrome_rec(char *str);
char *talloc(size_t num_chars);
char *get_string(FILE *f);

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
  bool result;
  char *new_str = NULL;
  size_t len_str = strlen(str);

  if (str[0] != str[len_str - 1])
    return false;
  else if (len_str > 3)
  {
    new_str = talloc(len_str - 1);
    strncpy(new_str, &str[1], len_str - 2);
    result = is_palindrome_rec(new_str);
    
    free(new_str);
    
    return result;
  }
  
  return true;
}

char *talloc(size_t num_chars)
{
  char *p = (char*)calloc(num_chars, sizeof(char));
  if (p == NULL)
  {
    printf("\nCouldn't allocate memory");
    exit(EXIT_FAILURE);
  }
  return p;
}

char *get_string(FILE *f)
{
  int c, i = 0;
  char *word = (char*)malloc(sizeof(char));

  word[0] = '\0'; /* prevents the program from crashing if the user don't enter anything */

  while ((c = fgetc(f)) != EOF && c != '\n')
  {
    word = (char*)realloc(word, ++i + 1);
    word[i - 1] = c;
    word[i] = '\0';
  }

  return word;
}
