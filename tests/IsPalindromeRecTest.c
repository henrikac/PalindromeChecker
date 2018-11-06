#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"

typedef enum { false, true } bool;

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

void TestIsPalindromeRec1(CuTest *tc)
{
  char *input = "regninger";
  bool actual = is_palindrome_rec(input);
  bool expected = true;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeRec2(CuTest *tc)
{
  char *input = "palindrome";
  bool actual = is_palindrome_rec(input);
  bool expected = false;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeRec3(CuTest *tc)
{
  char *input = "kurt";
  bool actual = is_palindrome_rec(input);
  bool expected = false;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeRec4(CuTest *tc)
{
  char *input = "kajak";
  bool actual = is_palindrome_rec(input);
  bool expected = true;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeRec5(CuTest *tc)
{
  char *input = "dette er re etted";
  bool actual = is_palindrome_rec(input);
  bool expected = true;
  CuAssertTrue(tc, actual == expected);
}

CuSuite *PalindromeRecGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestIsPalindromeRec1);
  SUITE_ADD_TEST(suite, TestIsPalindromeRec2);
  SUITE_ADD_TEST(suite, TestIsPalindromeRec3);
  SUITE_ADD_TEST(suite, TestIsPalindromeRec4);
  SUITE_ADD_TEST(suite, TestIsPalindromeRec5);
  return suite;
}
