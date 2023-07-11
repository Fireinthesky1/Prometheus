// Test Bed for the compiler

#include <stdio.h>

#include "data_structures.h"

//Research keyword static
static char lookahead;

void match(char t)
{
    if(lookahead == t)
    {
        lookahead = fgetc();
    }
    else
    {
        printf("SYNTAX ERROR\n");
        return -1;
    }
}

void term()
{
    int value_of_lookahead = (int)lookahead;

    if(value_of_lookahead >= 48 && <= 57)
    {
        printf('lookahead');
        match(lookahead);
    }
    else
    {
        printf("SYNTAX ERROR\n");
        return -1;
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
            printf('+');
        }
        else if(lookahead == '-')
        {
            match('-');
            term();
            printf('-');
        }
        else
        {
            return;
        }
    }
}

int main(void)
{
    expr();
    printf('\n');
    return 0;
}