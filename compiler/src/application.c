// Test Bed for the compiler

#include <stdio.h>
#include "data_structures.h"
#include "chtbl.h"


static char lookahead;
// TODO(James): de-global this glob
static FILE* file;

void match(char t)
{
    if(lookahead == t)
    {
        lookahead = fgetc(file);
    }
    else
    {
        printf("SYNTAX ERROR\n");
        return;
    }
}

void term()
{
    int value_of_lookahead = (int)lookahead;

    if(value_of_lookahead >= 48 && value_of_lookahead <= 57)
    {
        printf("%c",lookahead);
        match(lookahead);
    }
    else
    {
        printf("SYNTAX ERROR\n");
        return;
    }
}

void expr()
{
    term();
    while(1)
    {
        if(lookahead == '+')
        {
            match('+');
            term();
            printf("+");
        }
        else if(lookahead == '-')
        {
            match('-');
            term();
            printf("-");
        }
        else
        {
            return;
        }
    }
}

int main(void)
{
    // TEST FOR LINKED LIST
    
    return 0;
}