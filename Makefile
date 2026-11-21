# Compiler used to build the application and tests.
CC := gcc

# Compiler options:
# -Wall -Wextra -Wpedantic show useful warnings.
# -std=c11 selects the C11 language standard.
# -g adds information required by the debugger.
# -O0 disables optimisation, making debugging easier.
CFLAGS := -Wall -Wextra -Wpedantic -std=c11 -g -O0

# Source and header files used to build the interactive application.
#
# If you add or rename a .c or .h file, update these lists.
APP_SOURCES := main.c funcs.c input.c
APP_HEADERS := funcs.h input.h

# Source and header files used to build the separate unit-test program.
#
# The test program uses funcs.c directly, without compiling main.c
# or running the interactive command-line interface.
TEST_SOURCES := test_funcs.c funcs.c
TEST_HEADERS := funcs.h

# These are command names rather than files that Make should create.
.PHONY: all test clean

# Running make with no target builds the main application.
all: application.out

# Build the interactive application.
#
# This target is rebuilt if any application source or header file changes.
# $@ means the target name, which is application.out here.
application.out: $(APP_SOURCES) $(APP_HEADERS)
	$(CC) $(CFLAGS) $(APP_SOURCES) -o $@

# Build the separate unit-test executable.
#
# The tests compile against funcs.c but not main.c or input.c.
test_funcs.out: $(TEST_SOURCES) $(TEST_HEADERS)
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o $@

# Build and then run the unit tests.
#
# Running "make test" first creates test_funcs.out if required,
# then runs the completed test executable.
test: test_funcs.out
	./test_funcs.out

# Remove generated executable and object files.
#
# Run "make clean" before a complete rebuild.
clean:
	rm -f *.out *.o