#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackdata.h"


// This function creates and initialize a stackdata_t object. It allocates memory and copies the value from the provided data into its own container.
stackdata_t* createData(void* data, int dataType) 
{   
    // Allocate a new stackdata object
    stackdata_t* sd = (stackdata_t*) malloc(sizeof(stackdata_t));
    sd->dataType = dataType;

    // Sources from how to use malloc to allocate memory and copy value into allocated memory:
    // https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
    // ChatGPT, see kilder/chatlog1.txt

    // Store Integers
    if (dataType == DATA_TYPE_INT) 
    {
        // Allocate new pointer to store data using malloc
        int* ptr = malloc(sizeof(int));
        if (ptr == NULL) 
        {
            printf("ERROR - Memory not allocated\n");
            exit(0);
        }
        *ptr = *(int*) data; // Copy the integer value
        sd->data = ptr;
    } 

    // Store Floats
    else if (dataType == DATA_TYPE_FLOAT) 
    {
        // Allocate new pointer to store data using malloc
        float* ptr = malloc(sizeof(float));
        if (ptr == NULL) 
        {
            printf("ERROR - Memory not allocated\n");
            exit(0);
        }
        *ptr = *(float*) data; // Copy the integer value
        sd->data = ptr;
    } 
    
    // Store strings
    else if (dataType == DATA_TYPE_STRING) 
    {
        // Allocate new pointer to store data using malloc
        char *ptr = malloc(strlen( (char*)data ) + 1); // +1 for null terminator
        if (ptr == NULL) 
        {
            printf("ERROR - Memory not allocated\n");
            exit(0);
        }
        strcpy(ptr, (char*) data); // Copy the item value onto our pointer
        sd->data = ptr;

    } 
    
    // If something went wrong
    else 
    {
        printf("Unsupported data type!\n");
        sd->data = NULL;
        sd->dataType = 0;
    }

    // Return the data
    return sd;
}


// Function to free up the memory used by the stackdata object
void destroyData(stackdata_t* sd) 
{    
    if (sd->data)
    {
        free(sd->data);
        sd->data = NULL;
    }

    sd->dataType = 0;
    free(sd);
}


// This function prints the contents of a stackdata_t object based on its type
void printStackdata(stackdata_t* sd)
{
    if (sd == NULL)
    {
        printf("Stackdata is NULL, returning\n");
        return;
    }
    if (sd->dataType == DATA_TYPE_INT)
    {
        printf("Stackdata has an integer of value %d\n", *(int*) sd->data);
    }
    else if (sd->dataType == DATA_TYPE_FLOAT)
    {
        printf("Stackdata has an float of value %f\n", *(float*) sd->data);
    }
    else if (sd->dataType == DATA_TYPE_STRING)
    {
        printf("Stackdata has a string of value %s\n", (char*) sd->data);
    }
}
