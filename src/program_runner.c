#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program_runner.h"
#include "operations.h"


// Function run_program will iterate through every command of our program and dispatch them
int run_program(char **program)
{
    // Initialize stack for program
    stack_t* stack = stack_create();

    // Current program command
    char **command = program;
    int counter = 1000; // Safe counter to stop the program if it encounters an infinite loop
    while (*command != NULL)
    {
        // End if infinite loop
        counter--;
        if (counter == 0)
            break;
        
        //printf("Running program: %s\n", *command);
        int cJump_val = programDispatcher(stack, *command);
        if (cJump_val == 0) // If no cJump, increment the program counter and continue
        {
            command++;
            continue;;
        }
        else { // After counting I saw that we need to increment cJump_val once more when jumping ahead to correctly step ahead in array
            if (cJump_val > 0)
                cJump_val++;
        }

        // Increment the program counter, placing the next command of the program at *pc
        command += cJump_val;
    }

    return 0;
}


// Provided by ChatGPT, see kilder/chatlog2.txt
void trimFirstAndLast(char *str) {
    int len = strlen(str);
    if (len <= 2) {
        // If the string has 2 or fewer characters, clear it
        str[0] = '\0';
        return;
    }

    // Shift all characters to the left, skipping the first one
    memmove(str, str + 1, len - 1);

    // Null-terminate the string two characters earlier
    str[len - 2] = '\0';
}

/** Function programDispatcher dispatches the current command of the program onto our stack
 *  From Readme: 
 *   - anything enclosed in `~~` is a string
 *   - anything prefaced by `.` is an operation 
 *   - anything else is an integer
 */
int programDispatcher(stack_t* stack, char *command)
{
    // Strings are inserted onto the stack
    if (command[0] == '~')
    {
        // Strip first and last char as we dont need to store it in the stack
        trimFirstAndLast(command);

        // Push to stack
        stack_push(stack, command, DATA_TYPE_STRING);
    }

    // Operations are sent to our operationDispatcher
    else if (command[0] == '.')
    {
        return operationDispatcher(stack, command);
    }

    // Integers are also inserted onto the stack
    else
    {
        // Convert from string to integer
        int num1 = atoi(command);

        // Push to stack
        stack_push(stack, &num1, DATA_TYPE_INT);
    }

    return 0;
}


// This function dispatches the current operation to its respective function
int operationDispatcher(stack_t* stack, char *operation)
{
    // Goes through all supported opperations in a case switch
    //
    if (strcmp(operation, ".print") == 0) 
    {
        operation_print(stack);
    } 

    else if (strcmp(operation, ".newline") == 0)
    {
        operation_newline();
    }

    else if (strcmp(operation, ".+") == 0)
    {
        operation_add(stack);
    }

    else if (strcmp(operation, ".-") == 0)
    {
        operation_sub(stack);
    }

    else if (strcmp(operation, ".*") == 0)
    {
        operation_mul(stack);
    }

    else if (strcmp(operation, "./") == 0)
    {
        operation_div(stack);
    }

    else if (strcmp(operation, ".mod") == 0)
    {
        operation_mod(stack);
    }

    else if (strcmp(operation, ".=?") == 0)
    {
        operation_isEqual(stack);
    }

    else if (strcmp(operation, ".>?") == 0)
    {
        operation_isGreater(stack);
    }

    else if (strcmp(operation, ".dup") == 0)
    {
        operation_dup(stack);
    }

    else if (strcmp(operation, ".swap") == 0)
    {
        operation_swap(stack);
    }

    else if (strcmp(operation, ".cjump") == 0)
    {
        // Cjump, if returns a number not 0, jump that many operations
        int jumpVal = operation_cjump(stack);
        return jumpVal;
    }

    else /* default: */
    {
        printf("Unsupported operation: '%s'\n", operation);
    }

    return 0;
}

