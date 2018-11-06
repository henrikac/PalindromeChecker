#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

/**
 * Checks if a string is a palindrome by iterating through the string
 * @param[in] str The string to check
 * @return bool
*/
bool is_palindrome_iter(char *str)
{
  int i;
  size_t len_str = strlen(str);
  size_t iters = len_str % 2 == 0 ? len_str / 2 : (len_str + 1) / 2;

  for (i = 0; i < iters; i++)
    if (str[i] != str[(len_str - 1) - i])
      return false;

  return true;
}

/**
 * A function that checks if a string is a palindrome using recursion
 * @param[in] str The string to check
 * @return bool
*/
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

/**
 * Allocates num_chars bytes and checks if allocation is possible
 * @param[in] num_chars Number of characters to allocate memory for
 * @return char *
*/
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

/**
 * Creates a string from input stream
 * @param[in] f Input stream to read from
 * @return char *
*/
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
