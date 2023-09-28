#include <string.h>

#include "list.h"

/*
TODO(James): Figure out how the destroy function should work
             in order for this to be implemented as a symbol table
*/

// TODO(James): TEST
void list_init(List* list, void (*destroy)(void* data))
{
    // Initialize the list
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

// TODO(James):
// Fix this so list_rem_node works
void list_destroy(List* list)
{
    void* data;
    while(list->size > 0)
    {
        // If remove next is successful and destroy function is defined
        if(list_rem_node(list, (void**)&data) == 1 &&
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
    if(list->size == 0)
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
int list_rem_node(List* list, void** data)
{
    List_node* temp = list->head;

    // If the node is our head
    // TODO(James): What if head is the only node
    if(list->head->data == *data)
    {
        list->head = list->head->next;
        list->destroy(temp->data);
        list->size -= 1;
        if(list->head == NULL)
        {
            list->tail = NULL;
        }
        return 1;
    }

    // Traverse to node or end of bucket
    while(temp->next != NULL && temp->next->data != *data)
    {
        temp = temp->next;
    }

    // Are we at the Node
    if(temp->next->data == *data)
    {
        List_node* node_to_delete = temp->next;
        if(node_to_delete == list->tail)
        {
            list->tail = temp;
        }
        temp->next = temp->next->next;
        list->destroy(node_to_delete->data);
        list->size -= 1;
        return 1;
    }

    // We didn't find the node
    return 0;
}

// TODO(James): Implement get for attributes types and actions
void* list_data(const List_node* node)
{
    return node->data;
}