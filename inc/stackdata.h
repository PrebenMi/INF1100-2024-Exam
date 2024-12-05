#ifndef __STACKDATA_H__
#define __STACKDATA_H__

#define DATA_TYPE_INT 1
#define DATA_TYPE_FLOAT 2
#define DATA_TYPE_STRING 3

// Struct stackdata: contains a pointer to some data and a datatype Integer telling us which data is stored. 
// The following datatypes are supported: DATA_TYPE_INT, DATA_TYPE_FLOAT, DATA_TYPE_STRING
typedef struct stackdata {
    void* data;
    int dataType;
} stackdata_t;


// This function creates and initialize a stackdata_t object. It allocates memory and copies the value from the provided data into its own container.
stackdata_t* createData(void* data, int dataType);


// Function to free up the memory used by the stackdata object
void destroyData(stackdata_t* sd);


// This function prints the contents of a stackdata_t object based on its type
void printStackdata(stackdata_t* stackdata);


#endif