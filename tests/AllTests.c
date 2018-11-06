#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"

CuSuite *GetStringGetSuite();
CuSuite *PalindromeIterGetSuite();
CuSuite *PalindromeRecGetSuite();

void RunAllTests(void)
{
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  CuSuiteAddSuite(suite, GetStringGetSuite());
  CuSuiteAddSuite(suite, PalindromeIterGetSuite());
  CuSuiteAddSuite(suite, PalindromeRecGetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void)
{
  RunAllTests();

  return EXIT_SUCCESS;
}
