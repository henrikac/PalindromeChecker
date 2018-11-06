#include <stdio.h>

#include "CuTest.h"
#include "../src/palindrome.h"

void TestIsPalindromeIter1(CuTest *tc)
{
  char *input = "regninger";
  bool actual = is_palindrome_iter(input);
  bool expected = true;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeIter2(CuTest *tc)
{
  char *input = "palindrome";
  bool actual = is_palindrome_iter(input);
  bool expected = false;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeIter3(CuTest *tc)
{
  char *input = "kurt";
  bool actual = is_palindrome_iter(input);
  bool expected = false;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeIter4(CuTest *tc)
{
  char *input = "kajak";
  bool actual = is_palindrome_iter(input);
  bool expected = true;
  CuAssertTrue(tc, actual == expected);
}

void TestIsPalindromeIter5(CuTest *tc)
{
  char *input = "dette er re etted";
  bool actual = is_palindrome_iter(input);
  bool expected = true;
  CuAssertTrue(tc, actual == expected);
}

CuSuite *PalindromeIterGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestIsPalindromeIter1);
  SUITE_ADD_TEST(suite, TestIsPalindromeIter2);
  SUITE_ADD_TEST(suite, TestIsPalindromeIter3);
  SUITE_ADD_TEST(suite, TestIsPalindromeIter4);
  SUITE_ADD_TEST(suite, TestIsPalindromeIter5);
  return suite;
}
