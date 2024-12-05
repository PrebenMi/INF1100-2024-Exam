#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "list.h"

// Function to test the push and pop on stack with integer and string values
void testStack(stack_t* stack) 
{
    printf("### Testing stack functions\n");
    // Create a new stack

    // ========================  Stack push and pop: strings  ========================
    //
    printf("## Testing stackdata\n");
    stack_push(stack, "3", DATA_TYPE_STRING);
    stackdata_t* sd = stack_pop(stack);
    printStackdata(sd);
    destroyData(sd);

    int a = 3;
    stack_push(stack, &a, DATA_TYPE_INT);
    sd = stack_pop(stack);
    printStackdata(sd);
    destroyData(sd);


    // ========================  Stack push and pop: strings  ========================
    //
    printf("## Testing push and pop: strings\n");

    char* str1 = "Hello";
    char* str2 = "World";
    char* str3 = "Stack";

    // Push string items onto the stack
    printf("Pushing '%s' -> '%s' -> '%s'\n", str1, str2, str3);
    stack_push(stack, str1, DATA_TYPE_STRING);
    stack_push(stack, str2, DATA_TYPE_STRING);
    stack_push(stack, str3, DATA_TYPE_STRING);

    // Pop and check order (LIFO)
    stackdata_t* popStr1 = stack_pop(stack);
    stackdata_t* popStr2 = stack_pop(stack);
    stackdata_t* popStr3 = stack_pop(stack);

    printf("Popped: '%s'\n", (char*) popStr1->data);  // Expected "Stack"
    printf("Popped: '%s'\n", (char*) popStr2->data);  // Expected "World"
    printf("Popped: '%s'\n", (char*) popStr3->data);  // Expected "Hello"
    
    // Remember to free
    destroyData(popStr1);
    destroyData(popStr2);
    destroyData(popStr3);
    printf("\n");

    // ========================  Stack push and pop: integers  ========================
    //
    printf("## Testing push and pop: integers\n");
    // Test with integer values
    int int1 = 42;
    int int2 = 99;
    int int3 = 7;

    // Push integer items onto the stack
    printf("Pushing %d -> %d -> %d\n", int1, int2, int3);
    stack_push(stack, &int1, DATA_TYPE_INT);
    stack_push(stack, &int2, DATA_TYPE_INT);
    stack_push(stack, &int3, DATA_TYPE_INT);

    // Pop and check order (LIFO)
    stackdata_t* popInt1 = stack_pop(stack);
    stackdata_t* popInt2 = stack_pop(stack);
    stackdata_t* popInt3 = stack_pop(stack);

    printf("Popped: %d\n", *(int*) popInt1->data);  // Expected 7
    printf("Popped: %d\n", *(int*) popInt2->data);  // Expected 99
    printf("Popped: %d\n", *(int*) popInt3->data);  // Expected 42
    
    // Remember to free
    destroyData(popInt1);
    destroyData(popInt2);
    destroyData(popInt3);
    printf("\n");

    // Clean up
    stack_destroy(stack);
}