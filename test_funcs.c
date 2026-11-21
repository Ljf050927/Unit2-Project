// ELEC2645 Unit 2 Project Template
// Example unit tests for funcs.c.
//
// This file is compiled as a separate executable. It calls the reusable
// functions directly and does not run the interactive command-line program.

#include <stdio.h>
#include "funcs.h"

// Count how many tests have run and how many have failed.
//
// These variables are outside main(), so all functions in this file can
// access them. static prevents other .c files from accessing them.
static int tests_run = 0;
static int tests_failed = 0;

static void check_int(const char *test_name, int expected, int actual)
{
    tests_run++;

    printf("Test: %s\n", test_name);
    printf("  Expected: %d\n", expected);
    printf("  Actual:   %d\n", actual);

    if (expected == actual)
    {
        printf("  Result:   PASS\n\n");
    }
    else
    {
        printf("  Result:   FAIL\n\n");
        tests_failed++;
    }
}

int main(void)
{
    funcs_reset_operation_count();

    check_int("square positive integer", 25, square_int(5));
    check_int("square negative integer", 16, square_int(-4));
    check_int("cube positive integer", 27, cube_int(3));
    check_int("cube negative integer", -8, cube_int(-2));
    check_int("operation counter", 4, funcs_get_operation_count());

    printf("Tests run: %d\n", tests_run);
    printf("Tests failed: %d\n", tests_failed);

    if (tests_failed == 0)
    {
        printf("All tests passed.\n");
        return 0;
    }

    printf("Some tests failed.\n");
    return 1;
}
