// ELEC2645 Unit 2 Project Template
// Reusable validated terminal input.

#include <stdio.h>
#include "input.h"

int read_integer(const char *prompt, int *value)
{
    char line[64];
    char extra;

    printf("%s", prompt);

    // Read and consume one complete line of input.
    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        return 0;
    }

    // Attempt to read one integer followed by one extra character.
    // A return value of 1 means that one integer was read and there
    // was no additional non-whitespace text in the input line.
    if (sscanf(line, "%d %c", value, &extra) != 1)
    {
        return 0;
    }

    return 1;
}
