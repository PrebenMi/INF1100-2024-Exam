#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lexer_preprocessor.h"
#include "program_runner.h"

// Control Values
bool C_stack_input = false;

char **program;


int main(int argc, char **argv) {

  if (argc < 2) {
    printf("no program supplied\n");
    return 0;
  }

  // program is an array of strings; the end of the program is signified by a
  // NULL pointer.
  program = load_program(argv[1]);

  if (C_stack_input)
  {
    // prints out the words in the program array; uncomment to get an idea of how
    // the program is stored in memory.
    for (char **pc = program; *pc != NULL; pc++) {
        printf("program[%i]: %s\n", (int) (pc - program), *pc);
    }
  }

  run_program(program);
  

  return 0;
}
