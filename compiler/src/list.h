#pragma once

#include <stdlib.h>

/*
-Design:
    1) as this linked list is part of a chained hash table
    that implements a hash table we don't need to worry about 
    inserting in the middle of the list because insertions only happen
    at the end of buckets

    2) Implement destroy_node

*/

typedef struct List_node_
{
    void*  data;
    struct List_node* next;
} List_node;

typedef struct List_
{
    int        size;
    int  (*match)(const void* key1, const void* key2);
    void (*destroy)(void* data);
    List_node* head;
    List_node* tail;
} List;

void list_init(List* list, void (*destroy)(void* data));

void list_destroy(List* list);

// Returns 1 if successful; 0 otherwise
int list_append(List* list, const void* data);

// Returns 1 if successful; 0 otherwise
int list_rem_node(List* list, void** data);

void* list_data(const List_node* node);