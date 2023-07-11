//Data Structures for the compiler

/*
    TODO(James):
    1) [X] implement Binary Tree (general)
    2) [ ] implement Useful Binary Tree (specific)
    3) [ ] implement N-ary Tree (general)
    4) [ ] implement useful N-ary tree (specific)
    5) [ ] implement abstract syntax tree (general)
    6) [ ] implement useful abstract syntax tree (specific)
*/

typedef struct tree_node
{
    int val;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;