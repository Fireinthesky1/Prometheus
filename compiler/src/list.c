#include <string.h>

#include "list.h"

// TODO(James): TEST
void list_init(List* list, void (*destroy)(void* data))
{
    // Initialize the list
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

// TODO(James): TEST
void list_destroy(List* list)
{
    void* data;
    while(list_size(list) > 0)
    {
        // If remove next is successful and destroy function is defined
        if(list_rem_next(list, list->head, (void**)&data) == 1 &&
           list->destroy != NULL)
        {
            list->destroy(data);
        }
    }
    //clear the structure
    memset(list, 0, sizeof(List));
}

// TODO(James): TEST
// Returns 1 if successful; 0 otherwise.
int list_append(List* list, const void* data)
{
    List_node* new_node;

    // Allocate memory for the node
    if((new_node = (List_node*)malloc(sizeof(List_node))) == NULL)
    {
        return 0;
    }

    new_node->data = (void*)data;

    // Deal with empty list
    if(list_size(list) == 0)
    {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
        list->size++;
        return 1;
    }

    // Append
    list->tail->next = new_node;
    list->tail = new_node;
    new_node->next = NULL;
    list->size++;
    return 1;
}

// TODO(James): TEST
// Returns 1 if successful; 0 otherwise.
int list_rem_node(List* list, List_node* node, void** data);

// TODO(James): TEST
int list_size(const List* list);

// TODO(James): TEST
List_node* list_head(const List* list);

// TODO(James): TEST
List_node* list_tail(const List* list);

// TODO(James): TEST
// Returns 1 if the node is the head of the list
int list_is_head(const List_node* node);

// TODO(James): TEST
// Returns 1 if the node is the tail of the list
int list_is_tail(const List_node* node);

// TODO(James): TEST
// Returns the data of a node
void* list_data(const List_node* node);

// TODO(James): TEST
List_node* list_next(const List_node* node);