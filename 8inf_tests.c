#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tests.h"

#include "stack.h"


// Small main function that calls my testStack function
int main(int argc, char **argv) 
{
	stack_t* stack = stack_create();
	testStack(stack);
  
  return 0;
}
