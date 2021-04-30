#ifndef _Transaction_H
#define _Transaction_H

typedef struct transaction* Transaction; 

struct transaction
{
    int S_UID ;
    int R_UID ;
    double Amount ;
    Transaction Next;
};

#endif
