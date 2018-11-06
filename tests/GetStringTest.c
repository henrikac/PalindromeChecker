#include <stdio.h>
#include <string.h>

#include "CuTest.h"
#include "../src/palindrome.h"

void TestGetString1(CuTest *tc)
{
  FILE *input = fopen("testinput.txt", "r"); /* faking stdin */
  char *actual = get_string(input);
  char *expected = "test";
  fclose(input);
  CuAssertStrEquals(tc, expected, actual);
}

void TestGetString2(CuTest *tc)
{
  FILE *input = fopen("testinput.txt", "r"); /* faking stdin */
  char *actual = get_string(input);
  char *expected = "failing";
  fclose(input);
  CuAssertTrue(tc, strcmp(actual, expected) != 0);
}

CuSuite *GetStringGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestGetString1);
  SUITE_ADD_TEST(suite, TestGetString2);
  return suite;
}
