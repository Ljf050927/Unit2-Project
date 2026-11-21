// ELEC2645 Unit 2 Project Template
//
// This file contains a small command-line finite state machine.
// Replace and extend the example states to create your own application.

#include <stdio.h>
#include "funcs.h"
#include "input.h"

typedef enum
{
    STATE_MAIN_MENU,
    STATE_SQUARE,
    STATE_CUBE,
    STATE_EXIT
} AppState;

static void print_main_menu(void);
static AppState run_main_menu(void);
static void run_square_state(void);
static void run_cube_state(void);

int main(void)
{
    AppState state = STATE_MAIN_MENU;

    while (state != STATE_EXIT)
    {
        switch (state)
        {
            case STATE_MAIN_MENU:
                state = run_main_menu();
                break;

            case STATE_SQUARE:
                run_square_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_CUBE:
                run_cube_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_EXIT:
                break;

            default:
                printf("Unknown state. Returning to the main menu.\n");
                state = STATE_MAIN_MENU;
                break;
        }
    }

    printf("Exiting application.\n");
    return 0;
}

static AppState run_main_menu(void)
{
    int selection;

    print_main_menu();

    if (!read_integer("Select item: ", &selection))
    {
        printf("Invalid input. Please enter a menu number.\n");
        return STATE_MAIN_MENU;
    }

    switch (selection)
    {
        case 1:
            return STATE_SQUARE;

        case 2:
            return STATE_CUBE;

        case 3:
            return STATE_EXIT;

        default:
            printf("Invalid menu selection.\n");
            return STATE_MAIN_MENU;
    }
}

static void print_main_menu(void)
{
    printf("\n+-----------------------------------+\n");
    printf("|       Unit 2 Project Template     |\n");
    printf("+-----------------------------------+\n");
    printf("|  1. Square an integer             |\n");
    printf("|  2. Cube an integer               |\n");
    printf("|  3. Exit                          |\n");
    printf("+-----------------------------------+\n");
}

static void run_square_state(void)
{
    int value;

    printf("\n>> Square an integer\n");

    if (!read_integer("Enter an integer: ", &value))
    {
        printf("Invalid integer. Returning to the menu.\n");
        return;
    }

    printf("Result: %d\n", square_int(value));
    printf("Library operations completed: %d\n", funcs_get_operation_count());
}

static void run_cube_state(void)
{
    int value;

    printf("\n>> Cube an integer\n");

    if (!read_integer("Enter an integer: ", &value))
    {
        printf("Invalid integer. Returning to the menu.\n");
        return;
    }

    printf("Result: %d\n", cube_int(value));
    printf("Library operations completed: %d\n", funcs_get_operation_count());
}
