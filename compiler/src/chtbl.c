#include "chtbl.h"

// Returns 1 if initialization is successful, 0 otherwise
int chtbl_init(
    chtbl* chtbl,
    int    num_buckets,
    int    (*hash) (const void* key),
    int    (*match) (const void* key1, const void* key2),
    void   (*destroy) (void* data))
{
    // Allocate space for the hash table
    if((chtbl->table = (List*)malloc(num_buckets*sizeof(List))) == NULL)
    {
        return -0;
    }

    // Initialize the buckets
    chtbl->num_buckets = num_buckets;
    for(int i = 0; i < chtbl->num_buckets; i++)
    {
        // TODO(James): What does this line of code do PG 153
        list_init(&chtbl->table[i], destroy)
    }

    // Encapsulate the funcions
    chtbl->hash = hash;
    chtbl->match = match;
    chtbl->destroy = destroy;
}

// Frees associated dynamically allocated memory
void chtbl_destroy(chtbl* chtbl)
{
    
}

// Returns 1 if insertion is successful, 0 otherwise
int chtbl_insert(chtbl* chtbl, const void* data);

// Returns 1 if removal is successful, 0 otherwise
int chtbl_remove(chtbl* chtbl, void** data);

// Returns 1 if the element is in the table, 0 otherwise
int chtbl_lookup(const chtbl* chtbl, void** data);

// Returns the number of elements in the table
int chtbl_size(chtbl* chtbl);