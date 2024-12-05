#include <stdlib.h>
#include <stdio.h>

#include "operations.h"
#include "stackdata.h"



// ========================  Operators on integers  ========================
//
// For any operator where order matters, eg. subtraction, multiplication, etc., we
// always use the top of the stack as the "second" number. IE. if the stack
// contains `a b` where `b` is the top of the stack, `.-` will push `a - b`. For
// example `3 2 .-` will push the result `1` to the stack; not `-1`.
//

// Function operation_add pops two numbers from the stack and pushes their sum
void operation_add(stack_t* stack)
{   
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    int pushVal = b + a;
    stack_push(stack, &pushVal, DATA_TYPE_INT);
}

// Function operation_sub pops two numbers from the stack and pushes their difference
void operation_sub(stack_t *stack)
{
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    int pushVal = b - a;
    stack_push(stack, &pushVal, DATA_TYPE_INT);
}

// Function operation_mul pops two numbers from the stack and pushes their multiple
void operation_mul(stack_t *stack)
{
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    int pushVal = b * a;
    stack_push(stack, &pushVal, DATA_TYPE_INT);
}

// Function operation_div pops two numbers from the stack and pushes the quotient of the second divided by the first.
void operation_div(stack_t *stack)
{
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    float pushVal = (float) b / a;
    stack_push(stack, &pushVal, DATA_TYPE_FLOAT);
}

// Function operation_mod pops two numbers from the stack and pushes the remainder of the second divided by the first.
void operation_mod(stack_t *stack)
{
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    int pushVal = b % a;
    stack_push(stack, &pushVal, DATA_TYPE_INT);
}

// Function operation_isEqual pops two numbers from the stack and pushes `1` if they are equal, `0` otherwise
void operation_isEqual(stack_t *stack)
{
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    int pushVal = 0;

    if (a == b)
        pushVal = 1;
    stack_push(stack, &pushVal, DATA_TYPE_INT);
}

// Function operation_isGreater pops two numbers from the stack and pushes `1` if the second one is larger than the first one, `0` otherwise
void operation_isGreater(stack_t *stack)
{
    // Get data from stack, popInt does free the data itself
    int a = stack_popInt(stack);
    int b = stack_popInt(stack);

    int pushVal = 0;

    if (b > a)
        pushVal = 1;
    stack_push(stack, &pushVal, DATA_TYPE_INT);
}


//  ========================   Stack operations    ========================
// 

// Function operation_dup pushes a copy of the top word of the stack
void operation_dup(stack_t *stack)
{
    stackdata_t* sd = stack_pop(stack);

    stack_push(stack, sd->data, sd->dataType);
    stack_push(stack, sd->data, sd->dataType);
    
    destroyData(sd);
}

// Function operation_swap swaps the two top values on the stack 
void operation_swap(stack_t *stack)
{
    stackdata_t* sd1 = stack_pop(stack);
    stackdata_t* sd2 = stack_pop(stack);

    stack_push(stack, sd1->data, sd1->dataType);
    stack_push(stack, sd2->data, sd2->dataType);

    destroyData(sd1);
    destroyData(sd2);
}


// ======================== Control flow operations ========================
//

/** Function operation_cjump pops two numbers off the stack. if the second number is not `0` the
 *  program jumps by as many words as the first number indicates. eg. in 
 *  `1 -3 .cjump` the number `1` indicates that a jump should happen and the
 *  number `-3` indicates that the program should jump three words back. If the
 *  program for instance is `... 5 6 .* 1 -3 .cjump` we will jump back to the
 *  word `.*`.
 */ 
int operation_cjump(stack_t *stack)
{
    stackdata_t* sd1 = stack_pop(stack);
    stackdata_t* sd2 = stack_pop(stack);

    int a = *(int*) sd1->data;
    int b = *(int*) sd2->data;

    destroyData(sd1);
    destroyData(sd2);

    // If second number is not '0'
    if (b != 0)
    {
        return a;
    }
    return 0;
}


//  ========================    I/O Operations     ========================
//

// Function operation_print pops a word from the stack and prints it to the terminal
void operation_print(stack_t *stack)
{
    stackdata_t* sd = stack_pop(stack);
    //logStackdata(sd);
    if (sd == NULL)
    {
        printf("Trying to print when stack is empty!");
        return;
    }

    // Now we use stackdata to determine which data we are working with and prints it
    if (sd->dataType == DATA_TYPE_INT) // Integer
    {
        printf("%d", *(int*) sd->data);
    }
    else if (sd->dataType == DATA_TYPE_FLOAT)
    {
        printf("%.2f", *(float*) sd->data);
    }
    else if (sd->dataType == DATA_TYPE_STRING)
    {
        printf("%s", (char*) sd->data);
    }
    else
    {
        printf("Error, uknown data type");
    }
    destroyData(sd);
}


// Function operation_newline outputs a newline character to terminal; does not alter the stack
void operation_newline()
{
    printf("\n");
}

