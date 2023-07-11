// Test Bed for the compiler

#include <stdio.h>

#include "data_structures.h"

// Recursive Descent Parser for
/*

S -> +SS | -SS | a

*/

typedef char terminal;

terminal lookahead;

void match(terminal t)
{

    if( lookahead == t )
    {
        // TODO(James): Make it so we read from a text file here
        lookahead = getchar();
    }
    else
    {
        printf("Syntax Error");
    }

}

// TODO(James): Verify with the boys on this one
void S()
{

    switch( lookahead )
    {
        case '+':
        {
            match('+')
            S();
            S();
        } break;

        case '-':
        {
            match('-');
            S();
            S();
        } break;

        case 'a':
        {
            match('a');
        } break;

        default:
        {
            // TODO(James): Implement Logger
            printf("Syntax Error");
        }
    }

}

int main(void)
{
    return 0;
}