#pragma once

#include <stdlib.h>

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
} list;

void list_init(List* list, void (*destroy)(void* data));

void list_destroy(List* list);

// Returns 1 if successful; 0 otherwise
int list_ins_next(List* list, List_node* node, const void* data);

// Returns 1 if successful; 0 otherwise
int list_rem_next(List* list, List_node* node, void** data);

int list_size(const List* list);

list_node* list_head(const List* list);

list_node* list_tail(const List* list);

// Returns 1 if the node is the head of the list
int list_is_head(const List_node* node);

// Returns 1 if the node is the tail of the list
int list_is_tail(const List_node* node);

void* list_data(const List_node* node);

list_node* list_next(const List_node* node);