// ELEC2645 Unit 2 Project Template
// Example reusable application functions.
//
// Keep suitable program logic in functions like these rather than placing
// every calculation inside main.c. This lets the same functions be called
// by the interactive application and by the separate unit-test program.

#include "funcs.h"

// This variable has is visible across the whole of funcs.c aka "file scope", so every function in funcs.c can access it.
// static prevents other .c files from accessing the variable directly.
// Other files must use the functions declared in funcs.h instead.
static int operation_count = 0;

int square_int(int value)
{
    operation_count++;
    return value * value;
}

int cube_int(int value)
{
    operation_count++;
    return value * value * value;
}

int funcs_get_operation_count(void)
{
    return operation_count;
}

void funcs_reset_operation_count(void)
{
    operation_count = 0;
}
