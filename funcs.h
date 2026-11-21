#ifndef FUNCS_H
#define FUNCS_H

// Example application functions used by both main.c and test_funcs.c.
int square_int(int value);
int cube_int(int value);

// Return the number of successful operations performed by this library.
int funcs_get_operation_count(void);

// Reset the counter. This is useful when tests need a known starting state.
void funcs_reset_operation_count(void);

#endif
