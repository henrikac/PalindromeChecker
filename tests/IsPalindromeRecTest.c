#include <stdio.h>

#include "CuTest.h"
#include "../src/palindrome.h"

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
