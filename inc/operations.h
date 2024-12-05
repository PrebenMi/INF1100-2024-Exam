#ifndef __STACK_FUNCTIONS__
#define __STACK_FUNCTIONS__

#include "stack.h"

// Operations, defined in README.md
// 

// ========================  Operators on integers  ========================
//
// For any operator where order matters, eg. subtraction, multiplication, etc., we
// always use the top of the stack as the "second" number. IE. if the stack
// contains `a b` where `b` is the top of the stack, `.-` will push `a - b`. For
// example `3 2 .-` will push the result `1` to the stack; not `-1`.
//

// Function operation_add pops two numbers from the stack and pushes their sum
void operation_add(stack_t *stack);

// Function operation_sub pops two numbers from the stack and pushes their difference
void operation_sub(stack_t *stack);

// Function operation_ul pops two numbers from the stack and pushes their multiple
void operation_mul(stack_t *stack);

// Function operation_div pops two numbers from the stack and pushes the quotient of the second divided by the first.
void operation_div(stack_t *stack);

// Function operation_mod pops two numbers from the stack and pushes the remainder of the second divided by the first.
void operation_mod(stack_t *stack);

// Function operation_isEqual pops two numbers from the stack and pushes `1` if they are equal, `0` otherwise
void operation_isEqual(stack_t *stack);

// Function operation_isGreater pops two numbers from the stack and pushes `1` if the second one is larger than the first one, `0` otherwise
void operation_isGreater(stack_t *stack);


//  ========================   Stack operations    ========================
// 

// Function operation_dup pushes a copy of the top word of the stack
void operation_dup(stack_t *stack);

// Function operation_swap swaps the two top values on the stack 
void operation_swap(stack_t *stack);


// ======================== Control flow operations ========================
//

/** Function operation_cjump pops two numbers off the stack. if the second number is not `0` the
 *  program jumps by as many words as the first number indicates. eg. in 
 *  `1 -3 .cjump` the number `1` indicates that a jump should happen and the
 *  number `-3` indicates that the program should jump three words back. If the
 *  program for instance is `... 5 6 .* 1 -3 .cjump` we will jump back to the
 *  word `.*`.
 */ 
int operation_cjump(stack_t *stack);


//  ========================    I/O Operations     ========================
//

// Function operation_print pops a word from the stack and prints it to the terminal
void operation_print(stack_t *stack);

// Function operation_newline outputs a newline character to terminal; does not alter the stack
void operation_newline();


#endif
