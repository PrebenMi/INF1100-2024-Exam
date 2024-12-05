#ifndef __PROGRAM_RUNNER_
#define __PROGRAM_RUNNER_

#include "stack.h"

// Function run_program will iterate through every command of our program and dispatch them
int run_program(char **program);


/** Function programDispatcher dispatches the current command of the program onto our stack
 *  From Readme: 
 *   - anything enclosed in `~~` is a string
 *   - anything prefaced by `.` is an operation 
 *   - anything else is an integer
 */
int programDispatcher(stack_t* stack, char *func);


// This function dispatches the current operation to its respective function
int operationDispatcher(stack_t* stack, char *operation);


#endif
