#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stackdata.h"


// Returns a newly created empty list.
list_t *list_create()
{
    // Allocate a new list
    list_t* new_list = (list_t*) malloc(sizeof(list_t));

    // Populate
    new_list->head = NULL;
    new_list->count = 0;

    return new_list;
}


// Deallocate the entire list, all nodes and the contents contained.
void list_destroy(list_t *list)
{
    node_t* cur = list->head;
    node_t* next = NULL;

    while (cur != NULL)
    {
        // Get the next one
        next = cur->next;

        // Free the data
        destroyData(cur->data);
        free(cur);

        // Move forward
        cur = next;
    }
}


// Creates a new node with the provided stackdata and places it on top of the list
void list_add(list_t *list, stackdata_t* sd)
{
    // Store a pointer to the current head
    node_t* currentHead = list->head;

    // Create the new node to be inserted
    node_t* new = (node_t*) malloc(sizeof(node_t)); 
    new->data = sd;
    new->next = currentHead;

    // Place the new node first
    list->head = new;
    list->count++;
}


// Removes the top node of the list, returning the data contained. 
stackdata_t* list_remove(list_t *list) 
{
    // Check if the list is empty
    if (list->head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    // Get the first node and data
    node_t* firstNode = list->head;
    stackdata_t* data = firstNode->data;

    // Update the head to the next node
    list->head = firstNode->next;

    // Free, update list and return
    free(firstNode);
    list->count--;
    return data;
}