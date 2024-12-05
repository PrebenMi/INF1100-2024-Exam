#ifndef __STACK__
#define __STACK__

#include "stackdata.h"
#include "list.h"

/* My stack struct
 * Contains a pointer to a list, which holds all the elements contained in the stack.
 */
typedef struct stack {
    list_t *list;
} stack_t;


// Function that creates and returns a new empty stack struct
stack_t* stack_create();


// Function stack_destroy frees the memory allocated by the stack and its data container (list)
void stack_destroy(stack_t* stack);


// Pushes the given item to the top of the stack. Takes in a pointer to the given item, and the datatype of the item. 
// Item to store, the stack will copy the contents of the item so the passed variable is safe to remove after. 
// Data type constants: DATA_TYPE_INT, DATA_TYPE_FLOAT, DATA_TYPE_STRING
void stack_push(stack_t* stack, void* item, int dataType);


// Function stack_pop removes the item from the top of stack and returns it
// The returned data needs to be freed later using destroydata()
stackdata_t* stack_pop(stack_t* stack);


// Helper function to return an Integer value from top of the stack while also freeing the stackdata object
int stack_popInt(stack_t* stack);


// Helper function to print the entire stack, getting an overview of the data contained without changing its contents
void stack_print(stack_t* stack);


#endif
