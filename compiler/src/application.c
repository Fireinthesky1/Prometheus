// Test Bed for an implementation of trees

/*
    TODO(James):
    1) [X] implement Binary Tree (general)
    2) [ ] implement Useful Binary Tree (specific)
    3) [ ] implement N-ary Tree (general)
    4) [ ] implement useful N-ary tree (specific)
    5) [ ] implement abstract syntax tree (general)
    6) [ ] implement useful abstract syntax tree (specific)
*/

#include <stdio.h>

// Simple and general Binary Tree
typedef struct tree_node
{
    int val;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

// LEFT ROOT RIGHT
void in_order_printout(tree_node* root)
{
    if(root == NULL)
    {
        return;
    }
    in_order_printout(root->left);
    printf("%d\n", root->val);
    in_order_printout(root->right);
}

// ROOT LEFT RIGHT
void pre_order_printout(tree_node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\n", root->val);
    pre_order_printout(root->left);
    pre_order_printout(root->right);
}

// LEFT RIGHT ROOT
void post_order_printout(tree_node* root)
{
    if(root == NULL)
    {
        return;
    }
    post_order_printout(root->left);
    post_order_printout(root->right);
    printf("%d\n", root->val);
}

int main(void)
{
    tree_node one   = {0};
    tree_node two   = {0};
    tree_node three = {0};
    tree_node four  = {0};
    tree_node five  = {0};
    tree_node six   = {0};
    tree_node seven = {0};
    tree_node eight = {0};
    tree_node nine  = {0};
    tree_node ten   = {0};

    one.val   = 1;
    two.val   = 2;
    three.val = 3;
    four.val  = 4;
    five.val  = 5;
    six.val   = 6;
    seven.val = 7;
    eight.val = 8;
    nine.val  = 9;
    ten.val   = 10;

    one.left    = &two;
    one.right   = &three;

    two.left    = &four;
    two.right   = &five;

    three.left  = &six;
    three.right = &seven;

    four.left   = &eight;
    four.right  = &nine;

    five.left   = &ten;

    printf("in order traversal========================================\n");
    in_order_printout(&one);
    printf("in order traversal========================================\n");
    printf("pre order traversal=======================================\n");
    pre_order_printout(&one);
    printf("pre order traversal=======================================\n");
    printf("post order traversal======================================\n");
    post_order_printout(&one);
    printf("post order traversal======================================\n");
    while(1)
    {
    }
    return 0;
}