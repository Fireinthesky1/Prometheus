//Implementation of a chained hash table

#include <stdlib.h>

#include "list.h"

typedef struct chtbl_
{
    int    num_buckets;
    int    (*hash) (const void* key);
    int    (*match) (const void* key1, const void* key2);
    void   (*destroy) (void* data);
} chtbl;

// Returns 1 if initialization is successful, 0 otherwise
int chtbl_init(
    chtbl* chtbl,
    int    num_buckets,
    int    (*hash) (const void* key),
    int    (*match) (const void* key1, const void* key2),
    void   (*destroy) (void* data));

// Frees associated dynamically allocated memory
void chtbl_destroy(chtbl* chtbl);

// Returns 1 if insertion is successful, 0 otherwise
int chtbl_insert(chtbl* chtbl, const void* data);

// Returns 1 if removal is successful, 0 otherwise
int chtbl_remove(chtbl* chtbl, void** data);

// Returns 1 if the element is in the table, 0 otherwise
int chtbl_lookup(const chtbl* chtbl, void** data);

// Returns the number of elements in the table
int chtbl_size(chtbl* chtbl);

// P.J. Wienberg's hash function
int hashpwj(const void* key, int size)
{
    const char*  ptr;
    unsigned int val;
    while(*ptr != '\0')
    {
        unsigned int temp;
        val = (val << 4) + (*ptr);
        if(temp = (val & 0xf0000000))
        {
            val = val ^ (temp >> 24);
            val = val ^ tmp;
        }
        ptr++;
    }
    // TODO(JAMES): Consider function prime_nearest_size
    return val % size;
}