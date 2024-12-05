#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "stackdata.h"
#include "list.h"

const int C_logStack = 0; // Toggle to turn on print statements of elements moving in and out of the stack


// My stack implementation
// Ive deciding to use a single linked list so I dont have to worry about overflow in my program
// Sources used: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
// From this source ive scouted after what functions that defines a stack, and how they can be implemented. 
// I see from this source that I can implement the stack using linked-lists to no worry about overflow.
// The linked list implementation is gathered from assignment 3.


// Function that creates and returns a new empty stack struct
stack_t* stack_create()
{
    // Stack uses a single linked list implementation for storing data
    stack_t* new_stack = (stack_t*) malloc(sizeof(stack_t));
    new_stack->list = list_create();

    return new_stack;
}


// Function stack_destroy frees the memory allocated by the stack and its data container (list)
void stack_destroy(stack_t* stack) 
{
    if (stack == NULL) 
    {
        printf("Stack is NULL, returning\n");
        return; 
    }

    // Free the list then the stack
    list_destroy(stack->list);
    free(stack);
}


// Pushes the given item to the top of the stack. Takes in a pointer to the given item, and the datatype of the item. 
// Item to store, the stack will copy the contents of the item so the passed variable is safe to remove after. 
// Data type constants: DATA_TYPE_INT, DATA_TYPE_FLOAT, DATA_TYPE_STRING
void stack_push(stack_t* stack, void* item, int dataType)
{
    if (stack == NULL) 
    {
        printf("Stack is NULL, returning\n");
        return; 
    }

    // Some print statements used to debug stack push function
    if (C_logStack)
    {
        if (dataType == DATA_TYPE_INT)
            printf("Pushing int '%d' to stack at pos: [%d]\n", *(int*) item, stack->list->count);
        else if (dataType == DATA_TYPE_FLOAT)
            printf("Pushing float '%f' to stack at pos: [%d]\n", *(float*) item, stack->list->count);
        else if (dataType == DATA_TYPE_STRING)
            printf("Pushing string '%s' to stack at pos: [%d]\n", (char*) item, stack->list->count);
        else
            printf("Error, uknown dataType at push\n");
    }

    // Create the data and push to the stack list
    stackdata_t* stackdata = createData(item, dataType);
    list_add(stack->list, stackdata);
}


// Function stack_pop removes the item from the top of stack and returns it
// The returned data needs to be freed later using destroydata()
stackdata_t* stack_pop(stack_t* stack)
{
    if (stack == NULL) 
    {
        printf("Stack is NULL, returning\n");
        return NULL; 
    }

    // Pop from stack
    stackdata_t* sd = list_remove(stack->list);

    // Some print statements used to debug stack pop function
    if (C_logStack)
    {
        int dataType = sd->dataType;
        if (dataType == DATA_TYPE_INT)
            printf("Popped int '%d' from stack at pos: [%d]\n", *(int*) sd->data, stack->list->count);
        else if (dataType == DATA_TYPE_FLOAT)
            printf("Popped float '%f' from stack at pos: [%d]\n", *(float*) sd->data, stack->list->count);
        else if (dataType == DATA_TYPE_STRING)
            printf("Popped string '%s' from stack at pos: [%d]\n", (char*) sd->data, stack->list->count);
        else
            printf("Error, uknown dataType at pop\n");
    }

    return sd;
}


// Helper function to return an Integer value from top of the stack while also freeing the stackdata object
int stack_popInt(stack_t* stack)
{
    stackdata_t* sd = stack_pop(stack);

    if (sd->dataType != DATA_TYPE_INT)
    {
        printf("Trying to popInt from datatype %d\n", sd->dataType);
    }

    // Get integer value from stackdata
    int retInt = *(int*) sd->data;

    // Deallocate memory used by stackdata before returning the int value from the data
    destroyData(sd);
    return retInt;
}



// Helper function to print the entire stack, getting an overview of the data contained without changing its contents
void stack_print(stack_t* stack)
{
    // Start at head node
    node_t* currentNode = stack->list->head;
    printf("Stack contains %d elements\n", stack->list->count);
    int i = stack->list->count - 1;

    // Traverse the stack and print the content to console
    while (currentNode != NULL)
    {
        if (currentNode->data->dataType == DATA_TYPE_INT)
        {
            printf("[%d] has a int value of: %d\n", i, *(int*) currentNode->data->data);
        }
        else if (currentNode->data->dataType == DATA_TYPE_FLOAT)
        {
            printf("[%d] has a float value of: %f\n", i, *(float*) currentNode->data->data);
        }
        else if (currentNode->data->dataType == DATA_TYPE_STRING)
        {
            printf("[%d] has a str value of: %s\n",i, (char*) currentNode->data->data);
        }
        i--;
        currentNode = currentNode->next;
    }
}

