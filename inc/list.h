#ifndef __LIST_H__
#define __LIST_H__

#include "stackdata.h"


// My node struct, contains a pointer to the next node and a pointer to some stackdata
struct node {
    stackdata_t* data;
    struct node* next;
};
typedef struct node node_t;


// My list struct, contains a pointer to the head node and number of elements currently contained in the list
struct list {
    node_t* head;
    unsigned int count;
};
typedef struct list list_t;


// Returns a newly created empty list.
list_t *list_create(void);


// Deallocate the entire list, all nodes and the contents contained.
void list_destroy(list_t *list);


// Creates a new node with the provided stackdata and places it on top of the list
void list_add(list_t *list, stackdata_t* stackdata);


// Removes the top node of the list, returning the data contained. 
stackdata_t* list_remove(list_t *list);


#endif
